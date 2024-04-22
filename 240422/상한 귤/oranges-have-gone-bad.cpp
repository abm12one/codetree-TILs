#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n,k;
vector<vector<int>>map;
vector<vector<int>>visit;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){
    if(x<1||x>n)return 0;
    if(y<1||y>n)return 0;
    return 1;
}

int main() {
    
    cin>>n>>k;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    visit=vector<vector<int>>(n+1,vector<int>(n+1,-1));

    queue<pair<int,int>>q;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                q.push(make_pair(i,j));
                visit[i][j]=0;
            }
        }
    }

    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!range(ny,nx))continue;
            if(map[ny][nx]==0)continue;
            if(map[ny][nx]==1&&visit[ny][nx]==-1){
                q.push(make_pair(ny,nx));
                visit[ny][nx]=visit[y][x]+1;
            }
        }

    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==0){
                cout<<-1<<' ';
            }
            else if(map[i][j]==1&&visit[i][j]==-1){
                cout<<-2<<' ';
            }
            else{
                cout<<visit[i][j]<<' ';
            }
        }
        cout<<'\n';
    }


}