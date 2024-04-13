#include <iostream>
#include <vector>

using namespace std;
int n,m;
vector<vector<int>>map;
int ans=0;

void checky(int y){
    int temp=map[y][0];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(temp==map[y][i]){
            cnt++;
        }
        else{
            cnt=1;
        }
        temp=map[y][i];

    }
    if(cnt>=m){
        ans++;
    }
    return;

}
void checkx(int x){
    int temp=map[0][x];
    int cnt=1;
    for(int i=1;i<n;i++){
        if(temp==map[i][x]){
            cnt++;
        }
        else{
            cnt=1;
        }
        temp=map[i][x];

    }
    if(cnt>=m){
        ans++;
    }
    return;

}

int main() {
    
    cin>>n>>m;
    map=vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        checkx(i);
        checky(i);
    }

    cout<<ans;
 


}