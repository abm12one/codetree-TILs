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
vector<int>visit;
vector<int>dis;
vector<vector<pair<int,int>>>m;

int mnum;
int st;

void dfs(int n){
	
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i].first;
		if(visit[there]==0){
			
			visit[there]=1;
			dis[there]=dis[n]+m[n][i].second;
			dfs(there);
			
		}
	}
	
	if(mnum<dis[n]){
		mnum=dis[n];
		st=n;
	}
	return;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	m=vector<vector<pair<int,int>>>(n+1);
	dis=vector<int>(n+1,0);
	visit=vector<int>(n+1,0);
	
	for(int i=0;i<n-1;i++){
		int a,b,v;
		cin>>a>>b>>v;
		m[a].push_back(make_pair(b,v));
		m[b].push_back(make_pair(a,v));
		
	}
	
	mnum=0;
	visit[1]=1;
	dfs(1);
	
	dis=vector<int>(n+1,0);
	visit=vector<int>(n+1,0);
	
	mnum=0;
	visit[st]=1;
	dfs(st);
	
	cout<<mnum<<'\n';
	
}