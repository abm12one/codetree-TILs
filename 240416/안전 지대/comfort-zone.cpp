#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;

vector<vector<int>>map;
vector<vector<int>>visit;

int maxh=0;
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int k;

int isrange(int y,int x){
    if(y<0||y>n)return 0;
    if(x<0||x>m)return 0;
    return 1;
}

void dfs(int y,int x){
    
    visit[y][x]=1;
    
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!isrange(ny,nx))continue;
        if(map[ny][nx]>0&&visit[ny][nx]==0){
            dfs(ny,nx);
        }
    }
    return;


}

int pcnt=0;
int maxk=0;

void pr(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<visit[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int main() {
    
    cin>>n>>m;
    map=vector<vector<int>>(n+1,vector<int>(m+1));
    visit=vector<vector<int>>(n+1,vector<int>(m+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
            maxh=max(maxh,map[i][j]);
        }
    }

    int cnt=0;

    for(k=1;k<=maxh;k++){
        cnt=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                map[i][j]-=1;
            }
        }

        visit=vector<vector<int>>(n+1,vector<int>(m+1));

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(map[i][j]>0&&visit[i][j]==0){
                    //cout<<i<<" "<<j<<'\n';
                    dfs(i,j);
                    //pr();
                    cnt++;
                }
            }
        }
        /*
        cout<<k<<'\n';
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cout<<map[i][j]<<' ';
            }
            cout<<'\n';
        }
        cout<<cnt<<'\n';
        cout<<'\n';
        */
       

        if(cnt>pcnt){
            pcnt=cnt;
            maxk=k;
        }

    }
    cout<<maxk<<' '<<pcnt;

    



}