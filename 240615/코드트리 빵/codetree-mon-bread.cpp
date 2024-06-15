#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;

int n,m;
vector<vector<int>>map;
vector<vector<int>>mvisit;
vector<vector<int>>home;
vector<vector<int>>visit;
vector<pair<int,int>>conv;

int dy[4]={-1,0,0,1};
int dx[4]={0,-1,1,0};
int ans=0;

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}
void pr2(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<visit[i][j]<<' '; 
        }
        cout<<'\n';
    }
    cout<<'\n';
    cout<<'\n';
    return;
}

void sol(int t){

    int sy,sx;
    tie(sy,sx)=conv[t];

    queue<pair<int,int>>q;
    visit=vector<vector<int>>(n+1,vector<int>(n+1));
    q.push(make_pair(sy,sx));
    visit[sy][sx]=t;
    
    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];

            if(!range(ny,nx))continue;
            if(visit[ny][nx]!=0)continue;
            
            if(mvisit[ny][nx]!=0&&mvisit[ny][nx]<=visit[y][x]+1)continue;
            if(home[ny][nx]!=0)continue;
            if(map[ny][nx]==1){
                home[ny][nx]=1;
                mvisit[sy][sx]=visit[y][x]+1;
                visit[ny][nx]=visit[y][x]+1;
                ans=max(ans,mvisit[sy][sx]);
                //pr2();
                return;
            }
            visit[ny][nx]=visit[y][x]+1;
            q.push(make_pair(ny,nx));
        }
    }
    
    return;
}

void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cout<<mvisit[i][j]<<' '; 
        }
        cout<<'\n';
    }
    cout<<'\n';
    cout<<'\n';
    return;
}

int main() {
    
    cin>>n>>m;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    home=vector<vector<int>>(n+1,vector<int>(n+1));
    mvisit=vector<vector<int>>(n+1,vector<int>(n+1));
    conv=vector<pair<int,int>>(m+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=m;i++){
        int y,x;
        cin>>y>>x;
        conv[i]=make_pair(y,x);
    }
    
    for(int t=1;t<=m;t++){
        if(t<=m){
            sol(t);
            //pr();
        }
    }
    cout<<ans<<'\n';
    
}