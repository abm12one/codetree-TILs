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

typedef struct{
    int x;
    int y;
}node;

bool compare(node n1,node n2){
    return n1.x<n2.x;
}

vector<node>arr;
vector<vector<vector<int>>>dp;

int dist(int a,int b){
    int dy=(int)abs(arr[a].y-arr[b].y);
    int dx=(int)abs(arr[a].x-arr[b].x);
    return (int)pow(dy,2)+pow(dx,2);
}

int main() {
    
    int n;
    cin>>n;
    
    arr=vector<node>(n+1);
    arr[0]=node{0,0};
    for(int i=1;i<n+1;i++){
        int a,b;
        cin>>a>>b;
        arr[i]=node{a,b};
    }

    sort(arr.begin(),arr.end(),compare);

    dp=vector<vector<vector<int>>>(n+1,vector<vector<int>>(n+1,vector<int>(2,(int)2e9)));

    dp[1][1][0]=0;

    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){

            int k=max(i,j)+1;
            if(k==n+1){
                continue;
            }

            dp[k][j][0]=min(dp[k][j][0],dp[i][j][0]+dist(i,k));
            dp[i][k][0]=min(dp[i][k][0],dp[i][j][0]+dist(j,k));

            dp[k][j][1]=min(dp[k][j][1],min(dp[i][j][0],dp[i][j][1]+dist(i,k)));
            dp[i][k][1]=min(dp[i][k][1],min(dp[i][j][0],dp[i][j][1]+dist(j,k)));

        }
    }

    int ans=(int)2e9;
    for(int i=1;i<n+1;i++){
        ans=min(ans,dp[i][n][1]+dist(i,n));
        ans=min(ans,dp[i][n][0]);
        ans=min(ans,dp[n][i][1]+dist(i,n));
        ans=min(ans,dp[n][i][0]);
    }
    cout<<ans<<'\n';

	
}