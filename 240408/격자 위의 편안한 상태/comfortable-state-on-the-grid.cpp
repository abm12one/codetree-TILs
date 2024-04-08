#include <iostream>
#include <vector>

using namespace std;
int n,m;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

vector<vector<int>>map;
int ans=0;
int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

int sol(int y,int x){
    int ret=0;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!range(ny,nx))continue;
        if(map[ny][nx]==1)ret++;
    }
    if(ret==3)return 1;
    return 0;


}



int main() {

    
    cin>>n>>m;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=0;i<m;i++){
        int y,x;
        cin>>y>>x;
        map[y][x]=1;
        cout<<sol(y,x)<<'\n';
    }
    


  
}