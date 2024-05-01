#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;
int ans=0;
int n,q;
vector<vector<int>>map;
vector<vector<int>>visit;
int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

void shift(int i,int j,int len){
    vector<vector<int>>temp(len,vector<int>(len));
    
    for(int y=i;y<i+len;y++){
        for(int x=j;x<j+len;x++){
            temp[y-i][x-j]=map[y][x];
        }
    }

    
    for(int y=i+len;y<i+len+len;y++){
        for(int x=j;x<j+len;x++){
            map[y-len][x]=map[y][x];
        }
    }
    for(int y=i+len;y<i+len+len;y++){
        for(int x=j+len;x<j+len+len;x++){
            map[y][x-len]=map[y][x];
        }
    }
    for(int y=i;y<i+len;y++){
        for(int x=j+len;x<j+len+len;x++){
            map[y+len][x]=map[y][x];
        }
    }
    for(int y=0;y<len;y++){
        for(int x=0;x<len;x++){
            map[y+i][x+j+len]=temp[y][x];
        }
    }
    
    return;
}



void move(int lev){

    for(int i=1;i<=pow(2,n);i+=pow(2,lev)){
        for(int j=1;j<=pow(2,n);j+=pow(2,lev)){
            shift(i,j,pow(2,lev-1));
        }
    }
    return;

}

int isrange(int y,int x){
    if(y<1||y>pow(2,n))return 0;
    if(x<1||x>pow(2,n))return 0;
    return 1;
}

int check(int y,int x){
    int ret=0;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!isrange(ny,nx))continue;
        if(map[ny][nx]>0)ret++;
    }
    return ret;
}

void melt(){
    vector<vector<int>>temp(pow(2,n)+1,vector<int>(pow(2,n)+1,0));

    for(int i=1;i<=pow(2,n);i++){
        for(int j=1;j<=pow(2,n);j++){
            if(map[i][j]==0)continue;
            int ch=check(i,j);  
            if(ch<3){
                temp[i][j]=-1;
            }
        }
    }
    for(int i=1;i<=pow(2,n);i++){
        for(int j=1;j<=pow(2,n);j++){
            map[i][j]+=temp[i][j];
            if(map[i][j]<0)map[0][0];
        }
    }
    return;

}

void pr(){
    for(int i=1;i<=pow(2,n);i++){
        for(int j=1;j<=pow(2,n);j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void hap(){
    int ret=0;
    for(int i=1;i<=pow(2,n);i++){
        for(int j=1;j<=pow(2,n);j++){
            ret+=map[i][j];
        }
        
    }
    cout<<ret<<'\n';
    return ;
}


void bfs(int r,int c){
    int ret=0;
    queue<pair<int,int>>q;
    visit[r][c]=1;
    q.push(make_pair(r,c));

    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        ret++;
        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!isrange(ny,nx))continue;
            if(map[ny][nx]>0&&visit[ny][nx]==0){
                visit[ny][nx]=1;
                q.push(make_pair(ny,nx));
            }
        }
    }
    ans=max(ans,ret);
    return ;

}

int main() {
    
    cin>>n>>q;
    map=vector<vector<int>>(pow(2,n)+1,vector<int>(pow(2,n)+1));
    visit=vector<vector<int>>(pow(2,n)+1,vector<int>(pow(2,n)+1));
    for(int i=1;i<=pow(2,n);i++){
        for(int j=1;j<=pow(2,n);j++){
            cin>>map[i][j];
        }
    }

    for(int i=0;i<q;i++){
        int lev;
        cin>>lev;
        if(lev==0){
            melt();
            continue;
        }
        move(lev);
        //pr();
        melt();
        //pr();
    }

    hap();
    
    for(int i=1;i<=pow(2,n);i++){
        for(int j=1;j<=pow(2,n);j++){
            if(map[i][j]>0&&visit[i][j]==0){
                bfs(i,j);
            }
        }
    }
    cout<<ans;


}