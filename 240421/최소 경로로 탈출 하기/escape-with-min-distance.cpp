#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n,m;
vector<vector<int>>map;
vector<vector<int>>visit;
queue<pair<int,int>>q;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){
    if(x<1||x>m)return 0;
    if(y<1||y>n)return 0;
    return 1;

}

void bfs(int r,int c){
    q.push(make_pair(r,c));
    visit[r][c]=0;
    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!range(ny,nx))continue;
            if(map[ny][nx]==1&&visit[ny][nx]==-1){
                q.push(make_pair(ny,nx));
                visit[ny][nx]=visit[y][x]+1;
            }
        }

    }
    return;

}

int main() {

    cin>>n>>m;
    map=vector<vector<int>>(n+1,vector<int>(m+1));
    visit=vector<vector<int>>(n+1,vector<int>(m+1,-1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
        }
    }
    bfs(1,1);
    /*
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<visit[i][j]<<' ';
        }
        cout<<"\n";
    }
    cout<<"\n";
    */
    if(visit[n][m]!=0){
        cout<<visit[n][m];
    }
    else{
        cout<<-1;
    }

    


}