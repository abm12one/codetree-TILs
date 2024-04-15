#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>map;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};

void dfs(int y,int x){
    cout<<map[y][x]<<' ';
    int temp=map[y][x];
    int nexty=-1;
    int nextx=-1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];

        if(map[ny][nx]>temp){
            temp=map[ny][nx];
            nexty=ny;
            nextx=nx;
            break;
        }


    }
    if(nextx==-1){
        return;
    }
    else{
        dfs(nexty,nextx);
    }
    return;
}

int main() {

    int n,r,c;
    cin>>n>>r>>c;

    map=vector<vector<int>>(n+2,vector<int>(n+2));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    dfs(r,c);
    
}