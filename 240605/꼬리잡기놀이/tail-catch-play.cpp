#include <iostream>
#include <vector>
#include <tuple>
using namespace std;

int n,m,k;
vector<vector<int>>map;
vector<vector<int>>visit;
vector<vector<int>>group;
vector<int>tail;
vector<vector<pair<int,int>>>v;
vector<pair<int,int>>temp;
int ans=0;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=n)return 0;
    return 1;
}

void dfs(int y,int x,int cnt){
    v[cnt].push_back(make_pair(y,x));
    group[y][x]=cnt;
    visit[y][x]=1;

    for(int k=0;k<4;k++){
        int ny=y+dy[k];
        int nx=x+dx[k];
        if(!range(ny,nx))continue;
        if(visit[ny][nx]==1)continue;
        if(map[ny][nx]==0)continue;
        
        if(v[cnt].size()==1){
            if(map[ny][nx]==2){
                dfs(ny,nx,cnt);
            }
        }
        else{
            if(map[ny][nx]==3){
                tail[cnt]=v[cnt].size();
            }
            dfs(ny,nx,cnt);
        }
    }



}

void init(){
    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(map[i][j]==1){
                
                dfs(i,j,cnt);
                cnt++;
            }
        }
    }
    return;
}

pair<int,int> rcheck(int turn){

    if(turn>=1&&turn<=n){
        int now=turn-1;
        for(int i=0;i<n;i++){
            if(map[now][i]>0&&map[now][i]<4){
                return make_pair(now,i);
            }
        }
    }
    else if(turn>=n+1&&turn<=2*n){
        int now=turn-n-1;
        for(int i=n-1;i>=0;i--){
            if(map[i][now]>0&&map[i][now]<4){
                return make_pair(i,now);
            }
        }
    }
    else if(turn>=2*n+1&&turn<=3*n){
        int now=turn-(2*n)-1;
        for(int i=n-1;i>=0;i--){
            if(map[n-1-now][i]>0&&map[n-1-now][i]<4){
                return make_pair(n-1-now,i);
            }
        }
    }
    else if(turn>=3*n+1&&turn<=4*n){
        int now=turn-3*n-1;
        for(int i=n-1;i>=0;i--){
            if(map[i][n-1-now]>0&&map[i][n-1-now]<4){
                return make_pair(i,n-1-now);
            }
        }
    }
    return make_pair(-1,-1);

}

void move(int cnt){
    temp=vector<pair<int,int>>();
    int s=v[cnt].size();
    temp.push_back(v[cnt][s-1]);
    for(int i=0;i<=s-2;i++){
        temp.push_back(v[cnt][i]);
    }
    v[cnt]=temp;
    return;
}

void paint(){
    for(int i=0;i<m;i++){
        for(int j=0;j<v[i].size();j++){
            int y,x;
            tie(y,x)=v[i][j];
            if(j==0){
                map[y][x]=1;
            }
            else if(j>0&&j<tail[i]){
                map[y][x]=2;
            }
            else if(j==tail[i]){
                map[y][x]=3;
            }
            else{
                map[y][x]=4;
            }
        }
    }
    return;
}

void moveall(){

    for(int i=0;i<m;i++){
        move(i);
    }

    paint();
    return;

}

void pr(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
    return;
}

void rever(int cnt,int y,int x){
    for(int i=0;i<v[cnt].size();i++){
        int nowy,nowx;
        tie(nowy,nowx)=v[cnt][i];
        if(nowy==y&&nowx==x){
            ans+=(i+1)*(i+1);
        }
    }

    temp=vector<pair<int,int>>();
    int s=v[cnt].size();

    for(int i=tail[cnt];i>=0;i--){
        temp.push_back(v[cnt][i]);
    } 
    for(int i=s-1;i>=tail[cnt]+1;i--){
        temp.push_back(v[cnt][i]);
    } 
    v[cnt]=temp;

    return;
}

int main() {
    
    cin>>n>>m>>k;
    map=vector<vector<int>>(n,vector<int>(n));
    visit=vector<vector<int>>(n,vector<int>(n));
    group=vector<vector<int>>(n,vector<int>(n));
    v=vector<vector<pair<int,int>>>(m);
    tail=vector<int>(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    init();
    
    
    for(int t=1;t<=k;t++){
        moveall();
        
        int y=-1,x=-1;
        tie(y,x)=rcheck(t);
        if(y==-1&&x==-1)continue;
        //cout<<y<<" "<<x<<'\n';
        rever(group[y][x],y,x);
        //cout<<ans<<'\n';
        //pr();
        
    }
    cout<<ans<<'\n';
    




}