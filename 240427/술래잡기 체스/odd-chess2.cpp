#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
vector<vector<pair<int,int>>>map;


int dy[8]={-1,-1,0,1,1,1,0,-1};
int dx[8]={0,-1,-1,-1,0,1,1,1};
int score=0;
int ans=0;


int isrange(int y,int x){
    if(y<0||y>=4)return 0;
    if(x<0||x>=4)return 0;
    return 1;
}

tuple<int,int,int> getnext(int y,int x,int d){
    
    for(int rep=0;rep<8;rep++){
        int nd=(d+rep)%8;
        int ny=y+dy[nd];
        int nx=x+dx[nd];
        if(!isrange(ny,nx)){
            continue;
        }
        int nextp,nextd;
        tie(nextp,nextd)=map[ny][nx];
        if(nextp==17){
            continue;
        }
        return make_tuple(ny,nx,nd);
    }
    return make_tuple(-1,-1,-1);
}

void move(int n){
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int p,d;
            tie(p,d)=map[i][j];
            if(p==n){
                int ny,nx,nd;
                tie(ny,nx,nd)=getnext(i,j,d);
                if(ny==-1)return;
                int nextp,nextd;
                tie(nextp,nextd)=map[ny][nx];
                map[i][j]=make_pair(nextp,nextd);
                map[ny][nx]=make_pair(p,nd);
                return;
            }
           
        }
    }
    
}

void moveall(){
    for(int i=1;i<=16;i++){
        move(i);
    }
    return;
}


void pr(){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int p,d;
            tie(p,d)=map[i][j];
            cout<<p<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}


void bt(int r,int c,int score){
    
    
    
    ans=max(ans,score);
    //pr();
    moveall();
    //pr();
    vector<vector<pair<int,int>>>tmap(4,vector<pair<int,int>>(4));
    
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            tmap[i][j]=map[i][j];
        }
    }

    int nowp,nowd;
    tie(nowp,nowd)=map[r][c];
    
    for(int i=1;i<=3;i++){
        int ny=r+dy[nowd]*i;
        int nx=c+dx[nowd]*i;
        if(!isrange(ny,nx)){
            continue;
        }
        int nextp,nextd;
        tie(nextp,nextd)=map[ny][nx];
        if(nextp==0)continue;
        
        map[r][c]=make_pair(0,0);
        map[ny][nx]=make_pair(nowp,nextd);
       
        bt(ny,nx,score+nextp);
        for(int i=0;i<4;i++){
            for(int j=0;j<4;j++){
                map[i][j]=tmap[i][j];
            }
        }

    }
    
    
    


}

int main() {
    map=vector<vector<pair<int,int>>>(4,vector<pair<int,int>>(4));
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            int p,d;
            cin>>p>>d;
            map[i][j]=make_pair(p,d-1);
        }
    }

    int r,c;
    tie(r,c)=map[0][0];
    
    map[0][0]=make_pair(17,c);
    bt(0,0,r);
    cout<<ans;
    
}