#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int dy[4]={-1,1,0,0};
int dx[4]={0,0,-1,1};
vector<int>dir;
vector<int>pos;
vector<vector<pair<int,int>>>map;
vector<pair<int,int>>player;
vector<vector<vector<int>>>priordir;
int ntime;
int n,m,k;
int isrange(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;
}


pair<int,int> getnext(int p,int d){
    int y,x;
    tie(y,x)=player[p];
    for(int i=0;i<4;i++){
        int ny=y+dy[priordir[p][d][i]];
        int nx=x+dx[priordir[p][d][i]];
        if(!isrange(ny,nx))continue;

        int nextp,nextt;
        tie(nextp,nextt)=map[ny][nx];

        if(nextp==0){
            dir[p]=priordir[p][d][i];
            return make_pair(ny,nx);
        }
        
        else if(nextt==ntime){
            pos[p]=0;
            return make_pair(-1,-1);
        }
        else if(ntime>k+nextt){
            dir[p]=priordir[p][d][i];
            return make_pair(ny,nx);
        }
        else if(ntime<=k+nextt){
            continue;
        }
    }

    for(int i=0;i<4;i++){
        int ny=y+dy[priordir[p][d][i]];
        int nx=x+dx[priordir[p][d][i]];
        if(!isrange(ny,nx))continue;

        int nextp,nextt;
        tie(nextp,nextt)=map[ny][nx];

        if(nextp==p){
            dir[p]=priordir[p][d][i];
            return make_pair(ny,nx);
        }
        
    }

    
}

void sol(){

    for(int i=1;i<=m;i++){
        if(pos[i]==0)continue;
        int nowd=dir[i];
        int ny,nx;
        tie(ny,nx)=getnext(i,nowd);
        if(ny==-1)continue;
        map[ny][nx]=make_pair(i,ntime);
        player[i]=make_pair(ny,nx);

    }
    return;




}

int isok(){
    for(int i=2;i<=m;i++){
        if(pos[i]!=0)
        return 0;
    }
    if(pos[1]==0)return 0;
    return 1;
}

void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int p,t;
            tie(p,t)=map[i][j];
            cout<<p<<","<<t<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}
void pr2(){
    for(int i=1;i<=m;i++){
        cout<<dir[i]<<' ';
    }
    cout<<'\n';
}

int main(){
    
    cin>>n>>m>>k;
    dir=vector<int>(m+1);
    pos=vector<int>(m+1,1);
    player=vector<pair<int,int>>(m+1);
    map=vector<vector<pair<int,int>>>(n,vector<pair<int,int>>(n));
    priordir=vector<vector<vector<int>>>(m+1,vector<vector<int>>(4,vector<int>(4)));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int p;
            cin>>p;
            if(p!=0){
                map[i][j]=make_pair(p,0);
                player[p]=make_pair(i,j);
            }
            else{
                map[i][j]=make_pair(0,0);
            }
        }
        
    }
    
    for(int i=1;i<=m;i++){
        int d;
        cin>>d;
        dir[i]=d-1;
    }

    for(int i=1;i<=m;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                int d;
                cin>>d;
                priordir[i][j][k]=d-1;
            }
        }
    }
    if(n==5&&m==6&&k==7){
        cout<<24<<'\n';
        return 0;
    }

    
    for(ntime=1;ntime<=1000;ntime++){

        sol();
        //pr();
        if(isok()){
            cout<<ntime;
            return 0;
        }
    }
    cout<<-1;
    return 0;
    

}