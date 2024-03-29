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

int n,m,k;

vector<vector<pair<int,int>>>map;
vector<int>dis;
vector<int>visit;
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

int main() {

    cin>>n>>m>>k;
    map=vector<vector<pair<int,int>>>(n+1);
    dis=vector<int>(n+1,1e9);
    visit=vector<int>(n+1,0);

    for(int i=0;i<k;i++){
        int t;
        cin>>t;
        pq.push(make_pair(0,t));
        dis[t]=0;
    }

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        map[a].push_back(make_pair(b,c));
        map[b].push_back(make_pair(a,c));

    }

    int ans=0;
    while(!pq.empty()){
        int d,now;
        tie(d,now)=pq.top();
        pq.pop();

        if(d>dis[now])continue;
        visit[now]=1;
        ans+=dis[now];

        for(int i=0;i<map[now].size();i++){
            int next,nd;
            tie(next,nd)=map[now][i];
            if(visit[next])continue;
            if(dis[next]>nd){
                dis[next]=nd;
                pq.push(make_pair(nd,next));
            }
        }



    }
    cout<<ans;

    



 
}