#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <queue>
using namespace std;

int n,k,u,d;
int ans=987654321;
vector<vector<int>>map;
vector<vector<int>>visit;
vector<vector<int>>temp;
vector<pair<int,int>>city;
vector<int>arr;
int sy,sx,fy,fx;
int dy[4]={-1,0,1,0};
int dx[4]={0,1,0,-1};

int range(int y,int x){
    if(y<1||y>n)return 0;
    if(x<1||x>n)return 0;
    return 1;
}

void sol(){
    
    queue<pair<int,int>>q;
    visit=vector<vector<int>>(n+1,vector<int>(n+1,-1));
    temp=vector<vector<int>>(n+1,vector<int>(n+1));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            temp[i][j]=map[i][j];
        }
    }  

    for(int i=0;i<arr.size();i++){
        int r,c;
        tie(r,c)=city[arr[i]];
        
        temp[r][c]=0;

    }
    q.push(make_pair(sy,sx));
    visit[sy][sx]=0;
    while(!q.empty()){
        int y,x;
        tie(y,x)=q.front();
        q.pop();

        for(int i=0;i<4;i++){
            int ny=y+dy[i];
            int nx=x+dx[i];
            if(!range(ny,nx))continue;
            if(visit[ny][nx]==-1&&temp[ny][nx]==0){
                visit[ny][nx]=visit[y][x]+1;
                
                q.push(make_pair(ny,nx));
            }

        }

    }
    if(visit[fy][fx]!=-1){
        ans=min(ans,visit[fy][fx]);
    }
    return;

}

void bt(int now,int num){
    if(num==k){
        sol();
        return;
    }

    for(int i=now+1;i<city.size();i++){
        arr.push_back(i);
        bt(i,num+1);
        arr.pop_back();
    }
    return;

}

int main() {
    
    cin>>n>>k;

    map=vector<vector<int>>(n+1,vector<int>(n+1));
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                city.push_back(make_pair(i,j));
            }
           
        }
    }
    cin>>sy>>sx;
    cin>>fy>>fx;
    bt(-1,0);
    if(ans==987654321){
        cout<<-1;
    }
    else{
        cout<<ans;
    }
   

    



}