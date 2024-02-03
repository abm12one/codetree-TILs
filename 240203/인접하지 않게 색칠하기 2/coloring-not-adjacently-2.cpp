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
#include<unordered_map>
#include<map>
#include <unordered_set>
#include<set>

using namespace std;
vector<vector<int>>m;
vector<int>arr;
vector<int>visit;
vector<vector<vector<int>>>dp;
int n,k;

void dfs(int n){
	visit[n]=1;
	int left=0;
	int right=0;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i];
		if(visit[there]==1)continue;
		
		
		dfs(there);
		
		if(left==0){
			left=there;
		}
		else{
			right=there;
		}
		
	}
	
	dp[n][1][1]=arr[n];
	dp[n][0][0]=0;
	
	if(left!=0 && right!=0){
		for(int i=1;i<=k;i++){
			for(int j=0;j<i;j++){
				dp[n][i][1]=max(dp[n][i][1],dp[left][j][0]+dp[right][i-j-1][0]+arr[n]);
			}	
		}
		for(int i=0;i<=k;i++){
			for(int j=0;j<=i;j++){
				dp[n][i][0]=max(dp[n][i][0],max(dp[left][j][0],dp[left][j][1])+max(dp[right][i-j][0],dp[right][i-j][1]));
			}
		}	
	}
	
	
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	
	m=vector<vector<int>>(n+1);
	arr=vector<int>(n+1);
	visit=vector<int>(n+1);
	
	
	
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
		
	}
	
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	
	
	cin>>k;
	dp=vector<vector<vector<int>>>(n+1,vector<vector<int>>(k+1,vector<int>(2,0)));
	
	dfs(1);
	
	int ans=0;
	for(int i=1;i<=k;i++){
		ans=max(ans,dp[1][k][0]);
		ans=max(ans,dp[1][k][1]);
	}
	cout<<ans<<'\n';
	
}