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
int n,k;
int ans;
void dfs(int now,int num,int sum){
	
	
	if(num==4){
		ans=max(ans,sum);
		return ;
	}
	
	
	
	for(int i=0;i<m[now].size();i++){
		int there=m[now][i];
		visit[there]++;
	}
	
	for(int i=now+1;i<n+1;i++){
		if(visit[i]==0){
			visit[i]++;
			dfs(i,num+1,sum+arr[now]);
			visit[i]--;
		}

	}
	
	for(int i=0;i<m[now].size();i++){
		int there=m[now][i];
		visit[there]--;
	}
	return;
	
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
	
	for(int i=1;i<=n;i++){
		visit[i]++;
		dfs(i,0,arr[i]);
		visit[i]++;
	}
	cout<<ans;
}