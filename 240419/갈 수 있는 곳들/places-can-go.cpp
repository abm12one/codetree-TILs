#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
int n,m;
int cnt;
vector<vector<int>>map;
vector<vector<int>>visit;
queue<pair<int,int>>q;

int dy[4]={1,0,-1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){
    if(x<1||x>n)return 0;
    if(y<1||y>n)return 0;
    return 1;

}

void bfs(){
    
    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!range(ny,nx))continue;
            if(map[ny][nx]==0&&visit[ny][nx]==0){
                q.push(make_pair(ny,nx));
                visit[ny][nx]=1;
                cnt++;
                //cout<<ny<<' '<<nx<<'\n';
            }
        }

    }
    return;

}

int main() {

    cin>>n>>m;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    visit=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }
    cnt=0;
    for(int i=0;i<m;i++){
        int r,c;
        cin>>r>>c;
        q.push(make_pair(r,c));
        visit[r][c]=1;
        cnt++;
        //cout<<r<<' '<<c<<'\n';
    }
    bfs();
    
    cout<<cnt;

    


}