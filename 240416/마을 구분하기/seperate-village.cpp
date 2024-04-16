#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int cnt=0;
vector<vector<int>>map;
vector<vector<int>>visit;

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};

int isrange(int y,int x){
    
    if(y<0||y>n)return 0;
    if(x<0||x>n)return 0;
    return 1;

}

void dfs(int y,int x){
    cnt++;
    visit[y][x]=1;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(!isrange(ny,nx))continue;
        if(visit[ny][nx]==0&&map[ny][nx]==1){
            dfs(ny,nx);
        }
    }
}

int main() {
    
    cin>>n;
    cnt=0;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    visit=vector<vector<int>>(n+1,vector<int>(n+1));
    vector<int>ans;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(visit[i][j]==0&&map[i][j]==1){
                cnt=0;
                dfs(i,j);
                ans.push_back(cnt);
            }
        }
    }
    cout<<ans.size()<<'\n';
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<'\n';
    }



}