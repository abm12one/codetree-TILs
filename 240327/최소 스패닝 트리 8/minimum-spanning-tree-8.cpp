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

vector<int>dis;
vector<int>visit;
vector<vector<int>>map;

int main() {
    
    int n,m;
    cin>>n>>m;
    
    dis=vector<int>(n+1,2e9);
    visit=vector<int>(n+1,0);
    map=vector<vector<int>>(n+1,vector<int>(n+1,0));
    

    for(int i=0;i<m;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(map[a][b]==0){
            map[a][b]=c;
        }
        else{
            map[a][b]=min(map[a][b],c);
        }
        if(map[b][a]==0){
            map[b][a]=c;
        }
        else{
            map[b][a]=min(map[b][a],c);
        }
    }

    dis[1]=0;

    int ans=0;
    for(int r=0;r<n;r++){
        int mdis=2e9;
        int mid=-1;
        for(int i=1;i<=n;i++){
            if(visit[i])continue;
            if(dis[i]<mdis){
                mdis=dis[i];
                mid=i;
            }
        }
        if(mid==-1)break;

        visit[mid]=1;
        ans+=dis[mid];
        

        for(int i=1;i<=n;i++){
            if(map[mid][i]==0)continue;
            dis[i]=min(dis[i],map[mid][i]);
            
        }

    }
    cout<<ans;
    

 
}