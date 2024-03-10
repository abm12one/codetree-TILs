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
vector<int>arr;
vector<vector<int>>dp;

int dist(int a,int b){
    if(a==0||b==0){
        return 0;
    }
    return abs(arr[a]-arr[b]);

}

int main() {
    
    int n;
    cin>>n;
    arr=vector<int>(n+1);
    for(int i=1;i<n+1;i++){
        cin>>arr[i];
    }
    dp=vector<vector<int>>(n+1,vector<int>(n+1,(int)2e9));
    
    dp[0][0]=0;

    for(int i=0;i<n+1;i++){
        for(int j=0;j<n+1;j++){
            int k=max(i,j)+1;
            if(k==n+1){
                continue;
            }
            dp[i][k]=min(dp[i][k],dp[i][j]+dist(j,k));
            dp[k][j]=min(dp[k][j],dp[i][j]+dist(i,k));
        }
    }
    int ans=(int)2e9;
    for(int i=0;i<n;i++){
        ans=min(ans,dp[i][n]);
    }
    cout<<ans<<'\n';
	
}