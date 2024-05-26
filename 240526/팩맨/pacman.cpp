#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<int>>map;
int m,t;
int mr,mc;
pair<int,int>packman;
vector<tuple<int,int,int>>mon;
vector<tuple<int,int,int>>temp;
vector<tuple<int,int,int>>babymon;
vector<vector<int>>dead;
vector<int>path;

int range(int y, int x){
    if(x<1||x>4)return 0;
    if(y<1||y>4)return 0;
    return 1;
}

int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,-1,-1,-1,0,1,1,1};
tuple<int,int,int>anspath;
int mmax=0;

void pr(){
    int monr,monc;
    tie(monr,monc)=packman;
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<monr<<' '<<monc<<'\n';
    cout<<'\n';
    return;
}

void pr2(){
    
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            cout<<dead[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    cout<<'\n';
    return;
}

void duplicate(){
    babymon=mon;
    return;
}

void move(){
    int monr,monc;
    tie(monr,monc)=packman;
    //cout<<mon.size()<<'\n';
    
    for(int i=0;i<mon.size();i++){
        int r,c,d;
        tie(r,c,d)=mon[i];
        d=(d+7)%8;
        
        
        for(int k=0;k<8;k++){
            d=(d+1)%8;
            //cout<<d<<'\n';
            int ny=r+dy[d];
            int nx=c+dx[d];
            if(!range(ny,nx))continue;
            if(ny==monr&&nx==monc)continue;
            if(dead[ny][nx]>0)continue;
            mon[i]=make_tuple(ny,nx,d);
            break;    
        }
        

    }

    
    map=vector<vector<int>>(5,vector<int>(5));
    for(int i=0;i<mon.size();i++){
        int r,c,d;
        tie(r,c,d)=mon[i];
        //cout<<r<<' '<<c<<' '<<d<<'\n';
        map[r][c]++;
    }

    return;
    
    
}

void findpath(int now,int eat,int y,int x){
    //cout<<now<<' '<<eat<<" "<<y<<' '<<x<<'\n';
    if(now==3){
        if(eat>mmax){
            mmax=eat;
            anspath=make_tuple(path[0],path[1],path[2]);
            //cout<<"yaho"<<eat<<' '<<path[0]<<" "<<path[1]<<' '<<path[2]<<'\n';
        }
        return;
    }
    for(int i=0;i<=6;i+=2){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!range(ny,nx))continue;
        int temp=map[ny][nx];
        path.push_back(i);
        map[ny][nx]=0;
        findpath(now+1,eat+temp,ny,nx);
        path.pop_back();
        map[ny][nx]=temp;
    }
    return;
}

void pmove(){
    int monr,monc;
    tie(monr,monc)=packman;
    int y=monr;
    int x=monc;

    int f,s,t;
    tie(f,s,t)=anspath;
    //cout<<" "<<f<<' '<<s<<' '<<t<<'\n';
    int ny=y+dy[f];
    int nx=x+dx[f];
    if(map[ny][nx]>0){
        dead[ny][nx]=2;
        map[ny][nx]=0;
    }
    y=ny;
    x=nx;

    ny=y+dy[s];
    nx=x+dx[s];
    if(map[ny][nx]>0){
        dead[ny][nx]=2;
        map[ny][nx]=0;
    }
    y=ny;
    x=nx;

    ny=y+dy[t];
    nx=x+dx[t];
    if(map[ny][nx]>0){
        dead[ny][nx]=2;
        map[ny][nx]=0;
    }
    y=ny;
    x=nx;

    packman=make_pair(y,x);

    return;

}

void exo(){
    for(int i=1;i<5;i++){
        for(int j=1;j<5;j++){
            if(dead[i][j]==0)continue;
            dead[i][j]--;
        }
    }
    return;
}

void birth(){
    temp=vector<tuple<int,int,int>>();
    for(int i=0;i<mon.size();i++){
        int r,c,d;
        tie(r,c,d)=mon[i];
        if(map[r][c]==0)continue;
        temp.push_back(make_tuple(r,c,d));
    }
    mon=temp;

    for(int i=0;i<babymon.size();i++){
        mon.push_back(babymon[i]);
    }
    return;
}

void sol(){
    mmax=0;
    duplicate();
    move();
    //pr();
    
    
    int monr,monc;
    tie(monr,monc)=packman;
    findpath(0,0,monr,monc);
    
    pmove();
    
    exo();
    birth();
    
    
    

}

int main() {
    map=vector<vector<int>>(5,vector<int>(5));
    dead=vector<vector<int>>(5,vector<int>(5));
    cin>>m>>t;
    cin>>mr>>mc;
    packman=make_pair(mr,mc);

    for(int i=0;i<m;i++){
        int r,c,d;
        cin>>r>>c>>d;
        mon.push_back(make_tuple(r,c,d-1));
    }
    for(int i=0;i<t;i++){
        sol();
    }
    cout<<mon.size();

    

}