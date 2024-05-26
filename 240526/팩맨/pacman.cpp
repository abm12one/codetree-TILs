#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

vector<vector<int>>map;
int m,t;
int mr,mc;
pair<int,int>packman;
vector<vector<tuple<int,int,int>>>mon;
vector<vector<tuple<int,int,int>>>babymon;
vector<vector<tuple<int,int,int>>>dead;
vector<int>path;
int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,-1,-1,-1,0,1,1,1};


void duplicate(){
    babymon=mon;
    return;
}

void move(){
    int monr,monc;
    tie(monr,monc)=packman;

    for(int i=0;i<mon.size();i++){
        int r,c,d;
        tie(r,c,d)=mon[i];
        d=(d+7)%8;
        for(int k=0;k<8;k++){
            d=(d+1)%8;
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
        map[r][c]=++;
    }

    return;
}

void pmove(int now,int dir,int eat){
    if(now==3){

    }
    for(int dir=0;dir<=6;dir+=2){
        path.push_back(dir);
        pmove(now+1,dir,eat);
        path.pop_back();
    }
}

void sol(){
    duplicate();
    move();
    pmove();

}

int main() {
    map=vector<vector<int>>(5,vector<int>(5));
    
    cin>>m>>t;
    cin>>mr>>mc;
    packman=make_pair(mr,mc);

    for(int i=0;i<m;i++){
        int r,c,d;
        cin>>r>>c>>d;
        mon.push_back(make_tuple(r,c,d-1));
    }

    sol();

}