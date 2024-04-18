#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

vector<vector<int>>map;

int n,m,t,k;

vector<tuple<int,int,int>>marvel;
vector<int>speed;
vector<vector<vector<pair<int,int>>>>temp;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int dir(int d){
    if(d=='U')return 0;
    else if(d=='R')return 1;
    else if(d=='D')return 2;
    else if(d=='L')return 3;

}

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

int change(int d){
    if(d==0)return 2;
    else if(d==1)return 3;
    else if(d==2)return 0;
    else if(d==3)return 1;
}

void shift(int r,int c,int d,int id){
    int y=r;
    int x=c;
    int ny=0;
    int nx=0;
    for(int i=0;i<speed[id];i++){
        ny=y+dy[d];
        nx=x+dx[d];
        if(!range(ny,nx)){
            d=change(d);
            ny=y+dy[d];
            nx=x+dx[d];
        }
        y=ny;
        x=nx;
    }
    marvel[id]=make_tuple(ny,nx,d);
    temp[ny][nx].push_back(make_pair(speed[id],id));

}

void sol(){
    temp=vector<vector<vector<pair<int,int>>>>(n+1,vector<vector<pair<int,int>>>(n+1));
    for(int i=1;i<=m;i++){
        int y,x,d;
        tie(y,x,d)=marvel[i];
        if(y==0&&x==0)continue;
        shift(y,x,d,i);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int tsize=temp[i][j].size();
            if(tsize>k){
                sort(temp[i][j].begin(),temp[i][j].end(),greater<pair<int,int>>());
                for(int l=tsize-1;l>=k;l--){
                    int id=temp[i][j][l].second;
                    marvel[id]=make_tuple(0,0,0);
                }
            }
        }
    }
    return;

}

int main() {
    
    cin>>n>>m>>t>>k;
    speed=vector<int>(m+1);
    marvel.push_back(make_tuple(0,0,0));

    for(int i=1;i<=m;i++){
        int y,x;
        char d;
        cin>>y>>x>>d;
        cin>>speed[i];
        marvel.push_back(make_tuple(y,x,dir(d)));
        
    }

    while(t--){
        sol();
    }
    int ans=0;

    for(int i=1;i<=m;i++){
        int y,x,d;
        tie(y,x,d)=marvel[i];
        if(y==0&&x==0)continue;
        ans++;
    }
    cout<<ans;




    
}