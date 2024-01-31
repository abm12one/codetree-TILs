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
int ans;

vector<int>arr;
vector<int>visit;
vector<vector<int>>m;
vector<vector<int>>dp;

void dfs(int n){
	int flag=0;
	visit[n]=1;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i];
		
		if(visit[there]==0){
			flag=1;
			dfs(there);
			dp[n][1]+=dp[there][0];
			dp[n][0]+=max(dp[there][0],dp[there][1]);
		}
		
	}
	dp[n][1]+=arr[n];
	if(flag==0){
		dp[n][1]=arr[n];
		dp[n][0]=0;
	}
	return;
}

vector<int>answer;

void find(int n, int sum){
	//cout<<n<<' '<<sum<<"\n";
	visit[n]=1;
	
	if(dp[n][0]!=sum){
		answer.push_back(n);
		
		for(int i=0;i<m[n].size();i++){
			int there=m[n][i];
			if(visit[there]==1)continue;
			find(there,sum-arr[n]);
		}	
	}
	
	else{
		for(int i=0;i<m[n].size();i++){
			int there=m[n][i];
			if(visit[there]==1)continue;
			find(there,max(dp[there][0],dp[there][1]));
		}
	}	
	
	return;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	arr=vector<int>(n+1);
	visit=vector<int>(n+1);
	m=vector<vector<int>>(n+1);
	dp=vector<vector<int>>(n+1,vector<int>(2,0));
	for(int i=1;i<n+1;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	
	dfs(1);
	
	ans=max(dp[1][0],dp[1][1]);
	cout<<ans<<'\n';
	
	
	
	visit=vector<int>(n+1,0);
	find(1,ans);
	
	
	
	
	sort(answer.begin(),answer.end());
	for(int i=0;i<answer.size();i++){
		cout<<answer[i]<<' ';
	}
	
}