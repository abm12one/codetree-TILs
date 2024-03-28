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

int sol(int visit,int pre,int now){
    
    int dis=map[pre][now];
    int ret=0;
    for(int i=1;i<=n;i++){
        if(visit&(1<<i))continue;
        if(map[now][i]<=dis)continue;
        ret=max(ret,1+sol(visit|(1<<i),now,i));

    }
    return ret;

}


int main() {
 
    cin>>n;

    map=vector<vector<int>>(n+1,vector<int>(n+1,0));

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>map[i][j];
        }
    }
    
    cout<<sol(3,0,1)+1;


    

 
}