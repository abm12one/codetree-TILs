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
        map[a][b]=c;
    }

    dis[1]=0;

    int ans=0;
    for(int r=0;r<n;r++){
        int mdis=2e9;
        int mid=-1;
        for(int i=1;i<=n;i++){
            if(visit[i]==1)continue;
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