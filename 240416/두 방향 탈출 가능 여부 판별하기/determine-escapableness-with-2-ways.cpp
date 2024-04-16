#include <iostream>
#include <vector>

using namespace std;

int n,m;
vector<vector<int>>map;
vector<vector<int>>visit;

int dy[2]={1,0};
int dx[2]={0,1};

int isrange(int y,int x){
    
    if(y<0||y>n)return 0;
    if(x<0||x>m)return 0;
    return 1;

}

void dfs(int y,int x){
    visit[y][x]=1;
    for(int i=0;i<2;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!isrange(ny,nx))continue;
        if(visit[ny][nx]==0&&map[ny][nx]==1){
            dfs(ny,nx);
        }
    }
}

int main() {
    
    cin>>n>>m;
    
    map=vector<vector<int>>(n+1,vector<int>(m+1));
    visit=vector<vector<int>>(n+1,vector<int>(m+1));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
        }
    }

    dfs(1,1);
    if(visit[n][m]==1){
        cout<<1;
    }
    else{
        cout<<0;
    }



}