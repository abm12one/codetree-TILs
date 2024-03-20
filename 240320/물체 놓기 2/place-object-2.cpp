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
int n,k;
vector<int>p;
vector<vector<int>>dist;
vector<int>dp;

int cnts(int st){
    int ret=0;
    for(int i=0;i<n;i++){
        if(st&(1<<i)){
            ret++;
        }
    }
    return ret;

}

int main() {
    
    
    cin>>n>>k;
    p=vector<int>(n);
    dp=vector<int>((1<<n),1e9);
    dist=vector<vector<int>>(n,vector<int>(n));
    dp[0]=0;

    for(int i=0;i<n;i++){
        cin>>p[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>dist[i][j];
        }
    }

    for(int i=0;i<(1<<n);i++){

        for(int j=0;j<n;j++){

            if(i&(1<<j))continue;
            int mdist=p[j];

            for(int l=0;l<n;l++){
                if((i&(1<<l))){
                    mdist=min(mdist,dist[l][j]);
                }
            }
            dp[i+(1<<j)]=min(dp[i+(1<<j)],dp[i]+mdist);

        }

    }
    int ans=1e9;

    for(int i=0;i<(1<<n);i++){

        if(cnts(i)>=k){
            ans=min(ans,dp[i]);
        }
    }
    cout<<ans;


 
}