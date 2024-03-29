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

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>visit;
vector<int>dis;
vector<vector<int>>map;



int main() {
    
    int n,m,k;
    cin>>n>>m>>k;

    dis=vector<int>(n+1,1e9+5);
    visit=vector<int>(n+1,0);
    map=vector<vector<int>>(n+1,vector<int>(n+1,-1));

    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        map[0][i]=t;
        map[i][0]=t;
    }

    for(int i=1;i<=n;i++){
        if(i==n){
            map[i][1]=0;
            map[1][i]=0;
            
        }
        else{
            map[i][i+1]=0;
            map[i+1][i]=0;
        }
        
    }

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        map[a][b]=-1;
        map[b][a]=-1;
    }

    dis[0]=0;
    pq.push(make_pair(0,0));
    int ans=0;

    while(!pq.empty()){
        
        int d,now;
        tie(d,now)=pq.top();
        pq.pop();

        if(d>dis[now])continue;
        if(visit[now])continue;

        visit[now]=1;
        ans+=d;
        //cout<<d<<' '<<now<<'\n';
        
        if(ans>k){
            cout<<0;
            return 0;
        }
        

        for(int i=0;i<n+1;i++){
            if(visit[i])continue;
            if(map[now][i]==-1)continue;
            if(map[now][i]<dis[i]){
                dis[i]=map[now][i];
                pq.push(make_pair(map[now][i],i));
            }

        }


    }
    //cout<<ans<<'\n';
    if(ans>k){
        cout<<0;
    }
    else{
        cout<<1;
    }
    return 0;

    


}