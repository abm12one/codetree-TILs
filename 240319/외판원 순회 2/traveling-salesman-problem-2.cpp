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
vector<vector<int>>dp;

int n;

void sol(){

    dp[1][0]=0;
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            if(i&(1<<j)==0)continue;

            for(int k=0;k<n;k++){
                if(i&(1<<k))continue;
                if(map[j][k]==0)continue;

                dp[i+(1<<k)][k]=min(dp[i+(1<<k)][k],dp[i][j]+map[j][k]);

            }

        }
    }

}


int main() {
    
    cin>>n;
    
    map=vector<vector<int>>(n,vector<int>(n));
    dp=vector<vector<int>>((1<<n),vector<int>(n,(int)2e9));
   
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    sol();
    int ans=(int)1e9;
    for(int i=1;i<n;i++){
        if(map[i][0]==0)continue;
        ans=min(ans,dp[(1<<n)-1][i]+map[i][0]);



    }
    cout<<ans<<'\n';
    

 
}