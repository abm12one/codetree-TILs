#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
int ans=0;
int n,m;
int d;
tuple<int,int,int>dies;
vector<vector<int>>visit;
vector<vector<int>>map;
int y,x;
int dy[4]={0,1,0,-1};
int dx[4]={1,0,-1,0};

int range(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;
}

void roll(int dir){
    
    int ny=y+dy[dir];
    int nx=x+dx[dir];

    if(!range(ny,nx)){
        dir=(dir+2)%4;
        ny=y+dy[dir];
        nx=x+dx[dir];
        d=dir;
    };
    //cout<<"roll"<<'\n';
    //cout<<y<<' '<<x<<' '<<d<<"\n";
    int u,f,r;
    tie(u,f,r)=dies;

    if(d==0){
        dies=make_tuple(7-r,f,u);
    }
    if(d==1){
        dies=make_tuple(7-f,u,r);
    }
    if(d==2){
        dies=make_tuple(r,f,7-u);
    }
    if(d==3){
        dies=make_tuple(f,7-u,r);
    }
    y=ny;
    x=nx;
    //cout<<y<<' '<<x<<'\n';
    
    return;


}

int check(){
    //cout<<"check"<<'\n';
    //cout<<y<<' '<<x<<"\n";
    int ret=map[y][x];
    visit=vector<vector<int>>(n,vector<int>(n));
    queue<pair<int,int>>q;
    q.push(make_pair(y,x));
    visit[y][x]=1;
    
    while(!q.empty()){
        int nowy,nowx;
        tie(nowy,nowx)=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int ny=nowy+dy[i];
            int nx=nowx+dx[i];
            if(!range(ny,nx))continue;
            if(map[ny][nx]==map[y][x]&&visit[ny][nx]==0){
                q.push(make_pair(ny,nx));
                visit[ny][nx]=1;
                ret+=map[ny][nx];
            }
        }
    }
    return ret;
    
}


int main() {
    
    cin>>n>>m;
    d=0;
    y=0;
    x=0;
    dies=make_tuple(1,2,3);
    map=vector<vector<int>>(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<m;i++){
        
        int u,f,r;
        tie(u,f,r)=dies;
        if(i==0){
            roll(d);
        }
        else{
            if(map[y][x]<7-u){
                d=(d+1)%4;
                roll(d);
            }
            else if(map[y][x]>7-u){
                d=(d+3)%4;
                roll(d);
            }
            else{
                roll(d);
            }
        }

        ans+=check();
        //cout<<check()<<'\n';


    }
    cout<<ans;
}