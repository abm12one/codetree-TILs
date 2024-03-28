#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<limits.h>
#include<cassert>
//#include<unordered_map>
//#include<map>
#include<unordered_set>
#include<set>

using namespace std;

int n,m;
int inum;
vector<vector<int>>map;
vector<vector<int>>vmap;
vector<vector<int>>land;
vector<vector<int>>dis;
vector<int>dist;
vector<int>visit;

int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int isok(int y,int x){
    if(y<0||y>=n)return 0;
    if(x<0||x>=m)return 0;
    return 1;
}

void dfs(int y,int x){
    
    vmap[y][x]=1;
    land[y][x]=inum;
    for(int i=0;i<4;i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(isok(ny,nx)==0)continue;
        if(vmap[ny][nx]==1)continue;
        if(map[ny][nx]==0)continue;
        dfs(ny,nx);
    }
    return;
}

void bfs(int y,int x,int s,int dir,int d){
    
    
    int ny=y+dy[dir];
    int nx=x+dx[dir];
    if(isok(ny,nx))return;
    int e=land[ny][nx];
    if(e==0){
        bfs(ny,nx,s,dir,d+1);
    }
    if(e==s){
        return ;
    }
    else if(e!=s){
        dis[s][e]=min(dis[s][e],d);
    }

    return;

}

int main() {

    cin>>n>>m;
    
    map=vector<vector<int>>(n,vector<int>(m,0));
    vmap=vector<vector<int>>(n,vector<int>(m,0));
    land=vector<vector<int>>(n,vector<int>(m,0));

    dis=vector<vector<int>>(n+1,vector<int>(n+1,1e9));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
        }
    }

    inum=0;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(map[i][j]==0)continue;
            if(vmap[i][j]==1)continue;
            inum++;
            dfs(i,j);
        }
    }
    
    dis=vector<vector<int>>(inum+1,vector<int>(inum+1,1e9));
    dist=vector<int>(inum+1,(int)1e9);
    visit=vector<int>(inum+1,0);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(land[i][j]==0)continue;
            int s=land[i][j];
            for(int k=0;k<4;k++){
                int ny=i;
                int nx=j;
                int d=0;
                while(1){

                    ny+=dy[k];
                    nx+=dx[k];
                    d++;    
                    if(isok(ny,nx)==0)break;
                    if(land[ny][nx]==s)break;
                    if(land[ny][nx]!=0){
                        dis[s][land[ny][nx]]=min(dis[s][land[ny][nx]],d-1);
                        break;
                    }

                }   
                

                
            }
        }
    }
    /*
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<land[i][j]<<' ';
        }
        cout<<'\n';
    }
    
    for(int i=1;i<inum+1;i++){
        for(int j=1;j<inum+1;j++){
            cout<<dis[i][j]<<' ';
        }
        cout<<'\n';
    }
    */

    int ans=0;

    
    dist[1]=0;

    for(int i=0;i<inum;i++){
        int min_index = -1;
        for(int j=1;j<inum+1;j++){
            if(visit[j])continue;
            if(min_index == -1 || dist[min_index] > dist[j])
                min_index = j;

        }
        if(dist[min_index] == 1e9) {
            ans = -1;
            break;
        }
        visit[min_index]=1;
        ans+=dist[min_index];
        for(int j = 1; j < inum+1; j++) {
            dist[j] = min(dist[j], dis[min_index][j]);
        }






    }
    cout<<ans;
    



}