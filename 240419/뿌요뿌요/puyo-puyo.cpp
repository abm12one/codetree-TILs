#include <iostream>
#include <vector>
using namespace std;
int num;
int n;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>>map;
vector<vector<int>>visit;
int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

void dfs(int y,int x){
    num++;
    visit[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!range(ny,nx))continue;
        if((map[ny][nx]==map[y][x])&&(visit[ny][nx]==0)){
            dfs(ny,nx);
        }
    }
    return;
}

int cnt=0;
int ans=0;

void sol(int i,int j){
    num=0;
    dfs(i,j);
    
    if(num>=4){
        cnt++;
    }
    ans=max(ans,num);
    return;

}

int main() {
    
    cin>>n;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    visit=vector<vector<int>>(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }  

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visit[i][j]==0){
                sol(i,j);
            }
        }
    } 
    cout<<cnt<<" "<<ans;

}