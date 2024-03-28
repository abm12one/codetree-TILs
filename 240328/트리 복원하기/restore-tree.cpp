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
vector<int>visit;
vector<int>dis;
priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;

int main() {

    
    cin>>n;
    map=vector<vector<int>>(n+1,vector<int>(n+1));
    dis=vector<int>(n+1,1e9);
    visit=vector<int>(n+1,0);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }

    dis[1]=0;
    pq.push(make_tuple(0,0,1));
    
    vector<tuple<int,int,int>>ans;

    while(!pq.empty()){
        
        int d,pre,now;
        tie(d,pre,now)=pq.top();
        pq.pop();

        if(d>dis[now])continue;
        if(visit[now])continue;
        visit[now]=1;
        if(pre<now){
            ans.push_back(make_tuple(pre,now,d));
        }
        else{
            ans.push_back(make_tuple(now,pre,d));
        }

        for(int i=1;i<n+1;i++){
            if(visit[i])continue;
            if(map[now][i]<dis[i]){
                dis[i]=map[now][i];
                pq.push(make_tuple(map[now][i],now,i));
            }


        }



    }

    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){

        int a,b,w;
        tie(a,b,w)=ans[i];
        if(a==0)continue;
        cout<<a<<" "<<b<<" "<<w<<'\n';
    }




}