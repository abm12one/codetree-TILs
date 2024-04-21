#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <queue>
using namespace std;

int n,k,u,d;
int ans=0;
vector<vector<int>>map;
vector<vector<int>>visit;
vector<pair<int,int>>city;
vector<int>arr;

int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int cango(int a,int b){
    int ret=abs(a-b);
    if(ret>=u&&ret<=d)return 1;
    else{
        return 0;
    }
}

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

void sol(){
    int cnt=0;
    queue<pair<int,int>>q;
    visit=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=0;i<arr.size();i++){
        int r,c;
        tie(r,c)=city[arr[i]];
        q.push(make_pair(r,c));
        visit[r][c]=1;
        cnt++;

    }

    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!range(ny,nx))continue;
            if(!cango(map[y][x],map[ny][nx]))continue;
            if(visit[ny][nx]==0){
                visit[ny][nx]=1;
                cnt++;
                q.push(make_pair(ny,nx));
            }

        }


    }
    ans=max(ans,cnt);

}

void bt(int now,int num){
    if(num==k){
        sol();
        return;
    }

    for(int i=now+1;i<n*n;i++){
        arr.push_back(i);
        bt(i,num+1);
        arr.pop_back();
    }
    return;

}

int main() {
    
    cin>>n>>k>>u>>d;

    map=vector<vector<int>>(n+1,vector<int>(n+1));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            city.push_back(make_pair(i,j));
        }
    }

    bt(-1,0);
    cout<<ans;

    



}