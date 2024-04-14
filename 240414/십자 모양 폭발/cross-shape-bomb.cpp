#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int n;

vector<vector<int>>map;

void down(int x,int a,int b){
    int s=a-1;
    
    for(int i=a;i<=b;i++){
        map[i][x]=0;

    }

    for(int i=a-1;i>=1;i--){
        map[i+b+1-a][x]=map[i][x];
        map[i][x]=0;
    }
   

}


void sol(int y,int x,int t){
    int s,e;
    if(x-t+1<1){
        s=1;
    }
    else{
        s=x-t+1;
    }
    if(x+t-1>n){
        e=n;
    }
    else{
        e=x+t-1;
    }

    for(int i=s;i<=e;i++){
        down(i,y,y);
    }
    
    if(y-t+1<1){
        s=1;
    }
    else{
        s=y-t+1;
    }
    if(y+t-1>n){
        e=n;
    }
    else{
        e=y+t-1;
    }

    
    down(x,s+1,e);
    


}


int main() {
    
    
    cin>>n;

    map=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }
    int y,x;
    cin>>y>>x;
    sol(y,x,map[y][x]);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }

}