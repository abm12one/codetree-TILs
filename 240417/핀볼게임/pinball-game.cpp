#include <iostream>
#include <vector>
#include <tuple>
#include <list>
#include <unordered_set>

using namespace std;

int n;
int ans=0;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};
vector<vector<int>>map;
int range(int y,int x){
    if(y<1||y>n) return 0;
    if(x<1||x>n) return 0;
    return 1;
}
int t;
int changedir(int d,int mirror){
    if(mirror==1){
        return (5-d)%4;
    }
    else if(mirror==2){
        return 3-d;
    }
}

void dfs(int y,int x,int d){
    t++;
    int ny=y+dy[d];
    int nx=x+dx[d];
    if(!range(ny,nx))return;
    if(map[ny][nx]==0){
        dfs(ny,nx,d);
    }
    else{
        int ndir=changedir(d,map[ny][nx]);
        dfs(ny,nx,ndir);
    }
}

void sol(int y,int x,int d){
    t=0;
    dfs(y,x,d);
    ans=max(ans,t);
}


int main() {

   
    cin>>n;
    map=vector<vector<int>>(n+2,vector<int>(n+2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    for(int i=1;i<=n;i++){
        sol(i,0,1);
        sol(i,n+1,3);
        sol(0,i,2);
        sol(n+1,i,0);
    }
    cout<<ans;


    

    
    

}