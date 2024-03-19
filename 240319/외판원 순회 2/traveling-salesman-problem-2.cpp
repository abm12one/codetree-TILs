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

vector<vector<int>>map;

int n;

int ans=987654321;

void sol(int now,int mark,int dist){
    
    if(mark==((1<<n)-1)){
        
        if(map[now][0]==0)return;
        ans=min(ans,dist+map[now][0]);
        return;
    }
    for(int next=0;next<n;next++){
        if(mark&(1<<next)){
            continue;
        }
        
        if(now==next)continue;
        if(map[now][next]==0)continue;

        sol(next,mark|(1<<next),dist+map[now][next]);
    }
    return;

}


int main() {
    
    cin>>n;
    
    map=vector<vector<int>>(n,vector<int>(n));
   

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }

    sol(0,(1<<0),0);

    cout<<ans<<'\n';
 
}