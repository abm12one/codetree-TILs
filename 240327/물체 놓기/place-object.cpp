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

int n;
vector<vector<int>>map;
vector<int>dis;
vector<int>visit;

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
int main() {

    cin>>n;
    map=vector<vector<int>>(n+1,vector<int>(n+1,0));
    dis=vector<int>(n+1,1e9);
    visit=vector<int>(n+1,0);
    
    for(int i=1;i<=n;i++){
        int t;
        cin>>t;
        map[0][i]=t;
        //dis[i]=t;
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    int ans=0;
    pq.push(make_pair(0,0));
    dis[0]=0;

    while(!pq.empty()){
        int d,now;
        tie(d,now)=pq.top();
        pq.pop();

        //if(visit[now])continue;
        if(d>dis[now])continue;

        visit[now]=1;
        ans+=dis[now];

        for(int i=0;i<=n;i++){
            if(visit[i])continue;
            if(map[now][i]==0)continue;
            
            int next=i;
            int nd=map[now][i];
            
            if(dis[next]>nd){
                dis[next]=nd;
                pq.push(make_pair(nd,next));
            }

        }
    }
    cout<<ans<<'\n';

}