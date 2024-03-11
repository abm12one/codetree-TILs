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
#define MAX_M 100000

using namespace std;
vector<vector<vector<int>>>dp;
vector<int>arr;

int dist(int a,int b){
    if(a==0||b==0){
        return 0;
    }
    return abs(arr[a]-arr[b]);
}


int main() {
    int n,m;
    cin>>n>>m;
    arr=vector<int>(n+1);
    dp=vector<vector<vector<int>>>(n+1,vector<vector<int>>(n+1,vector<int>(m+1,(int)2e9)));

    for(int i=1;i<n+1;i++){
        cin>>arr[i];
    }

    dp[0][0][0]=0;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            for(int k=0;k<m+1;k++){
                int next=max(i,j)+1;
                if(next==n+1){
                    continue;
                }
                dp[i][next][k]=min(dp[i][next][k],dp[i][j][k]+dist(j,next));
                dp[next][j][k]=min(dp[next][j][k],dp[i][j][k]+dist(i,next));
                if(k==m)continue;
                dp[i][next][k+1]=min(dp[i][next][k+1],dp[i][j][k]);
                dp[next][j][k+1]=min(dp[next][j][k+1],dp[i][j][k]);

            }
        }

    }
    int ans=(int)2e9;
    for(int i=0;i<n;i++){
       
        ans=min(ans,dp[i][n][m]);

    }
    cout<<ans<<'\n';

	
}