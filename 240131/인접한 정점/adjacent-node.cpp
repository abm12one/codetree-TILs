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
vector<int>arr;
vector<int>visit;
vector<vector<int>>m;
vector<vector<int>>p;
void dfs(int n){
	int flag=0;
	visit[n]=1;
	
	for(int i=0;i<m[n].size();i++){
		
		int there=m[n][i];
		if(visit[there]==0){
			flag=1;
			dfs(there);
			p[n][0]+=max(p[there][0],p[there][1]);
			p[n][1]+=p[there][0];
		}
		
	}
	p[n][1]+=arr[n];
	
	if(flag==0){
		p[n][1]=arr[n];
		p[n][0]=0;
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
	p=vector<vector<int>>(n+1,vector<int>(2,0));
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
	cout<<max(p[1][1],p[1][0]);
}