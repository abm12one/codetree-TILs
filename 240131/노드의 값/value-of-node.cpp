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
vector<int>dp;
vector<int>arr;
vector<int>visit;
vector<vector<int>>m;
int ans;
void dfs(int n){
	
	dp[n]=arr[n];
	visit[n]=1;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i];
		if(visit[there]==0){
			
			dfs(there);
			dp[n]+=dp[there]-1;
			
		}
		
	}
	ans+=abs(dp[n]-1);
	return;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	ans=0;
	dp=vector<int>(n+1);
	arr=vector<int>(n+1);
	visit=vector<int>(n+1);
	m=vector<vector<int>>(n+1);
	for(int i=1;i<=n;i++){
		cin>>arr[i];

	}
	
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	
	dfs(1);
	cout<<ans<<'\n';
	
}