#include <iostream>
#include <vector>
#include <tuple>

using namespace std;
int n=4;
vector<vector<int>>map;


void shiftr(int y){
    vector<int>arr2(4);
    for(int i=0;i<4;i++){
        arr2[i]=map[y][i];
    }
    int s=0;
    vector<int>arr(4);{
        for(int i=0;i<4;i++){
            if(arr2[i]==0)continue;
            arr[s]=arr2[i];
            s++;
        }
    }
    for(int i=0;i<4;i++){
        map[y][i]=0;
    }
    for(int i=3;i>=1;i--){
        if(arr[i]==arr[i-1]){
            arr[i]+=arr[i-1];
            arr[i-1]=0;
            i--;
        }

    }
    s=3;
    for(int i=3;i>=0;i--){
        if(arr[i]==0)continue;
        map[y][s]=arr[i];
        s--;
    }
}
void shiftl(int y){
    vector<int>arr2(4);
    for(int i=0;i<4;i++){
        arr2[i]=map[y][i];
    }
    int s=0;
    vector<int>arr(4);{
        for(int i=0;i<4;i++){
            if(arr2[i]==0)continue;
            arr[s]=arr2[i];
            s++;
        }
    }
    for(int i=0;i<4;i++){
        map[y][i]=0;
    }
    for(int i=0;i<3;i++){
        if(arr[i]==arr[i+1]){
            arr[i]+=arr[i+1];
            arr[i+1]=0;
            i++;
        }

    }
    s=0;
    for(int i=0;i<4;i++){
        if(arr[i]==0)continue;
        map[y][s]=arr[i];
        s++;
    }



}
void shiftu(int x){
    vector<int>arr2(4);
    for(int i=0;i<4;i++){
        arr2[i]=map[i][x];
    }
    int s=0;
    vector<int>arr(4);{
        for(int i=0;i<4;i++){
            if(arr2[i]==0)continue;
            arr[s]=arr2[i];
            s++;
        }
    }
    for(int i=0;i<4;i++){
        map[i][x]=0;
    }
    for(int i=0;i<3;i++){
        if(arr[i]==arr[i+1]){
            arr[i]+=arr[i+1];
            arr[i+1]=0;
            i++;
        }

    }
    s=0;
    for(int i=0;i<4;i++){
        if(arr[i]==0)continue;
        map[s][x]=arr[i];
        s++;
    }
}
void shiftd(int x){
    vector<int>arr2(4);
    for(int i=0;i<4;i++){
        arr2[i]=map[i][x];
    }
    int s=0;
    vector<int>arr(4);{
        for(int i=0;i<4;i++){
            if(arr2[i]==0)continue;
            arr[s]=arr2[i];
            s++;
        }
    }

    for(int i=0;i<4;i++){
        map[i][x]=0;
    }
    for(int i=3;i>=1;i--){
        if(arr[i]==arr[i-1]){
            arr[i]+=arr[i-1];
            arr[i-1]=0;
            i--;
        }

    }
    s=3;
    for(int i=3;i>=0;i--){
        if(arr[i]==0)continue;
        map[s][x]=arr[i];
        s--;
    }

}
int main() {

    map=vector<vector<int>>(4,vector<int>(4));
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cin>>map[i][j];
        }
    }

    char c;
    cin>>c;
    if(c=='R'){
        for(int i=0;i<4;i++){
            shiftr(i);
        }
    }
    else if(c=='L'){
        for(int i=0;i<4;i++){
            shiftl(i);
        }
    }
    else if(c=='U'){
        for(int i=0;i<4;i++){
            shiftu(i);
        }
    }
    else if(c=='D'){
        for(int i=0;i<4;i++){
            shiftd(i);
        }
    }
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }

    
    


    
    

}