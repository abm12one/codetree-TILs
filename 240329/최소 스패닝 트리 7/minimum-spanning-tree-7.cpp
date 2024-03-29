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

#define MAX_K 100

using namespace std;

int n,m;
vector<vector<pair<int,int>>>map;
vector<int>dis;
vector<int>visit;
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
vector<vector<pair<int,int>>>gp;

void dfs(int now){
    
    visit[now]=1;
    for(int i=0;i<gp[now].size();i++){
        
        int next,d;
        tie(next,d)=gp[now][i];

        if(visit[next])continue;
        dis[next]=dis[now]+d;
        dfs(next);

    }
    return;



}



int main() {

    cin>>n>>m;
    map=vector<vector<pair<int,int>>>(n+1);
    dis=vector<int>(n+1,1e9);
    visit=vector<int>(n+1,0);
    gp=vector<vector<pair<int,int>>>(n+1);

    
    int sum=0;
    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        sum+=c;
        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));

    }

    pq.push(make_tuple(0,0,1));
    dis[1]=0;

    int ans=0;
    while(!pq.empty()){
        int d,pre,now;
        tie(d,pre,now)=pq.top();
        pq.pop();
        
        if(d>dis[now])continue;
        if(pre!=0){
            gp[pre].push_back(make_pair(now,d));
            gp[now].push_back(make_pair(pre,d));
        }
        
        visit[now]=1;
        
        ans+=dis[now];

        for(int i=0;i<map[now].size();i++){
            int next,nd;
            tie(next,nd)=map[now][i];
            if(visit[next])continue;
            if(dis[next]>nd){
                dis[next]=nd;
                pq.push(make_tuple(nd,now,next));
            }
        }
    }
    cout<<ans<<'\n';
    
    visit=vector<int>(n+1,0);
    dis=vector<int>(n+1,0);
    
    dis[1]=0;
    dfs(1);
    
    int s;
    int res=0;
    
    for(int i=1;i<n+1;i++){
        if(res<dis[i]){
            res=dis[i];
            s=i;
        }
    }

    visit=vector<int>(n+1,0);
    dis=vector<int>(n+1,0);

    dfs(s);
    res=0;
    
    for(int i=1;i<n+1;i++){
        if(res<dis[i]){
            res=dis[i];
        }
    }
    cout<<res;
    

   
    



 
}