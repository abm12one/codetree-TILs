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

int st;
int dis=0;
vector<vector<pair<int,int>>>m;
vector<int>visit;
vector<int>d;

int dp(int n){
	int value=0;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i].first;
		int vt=m[n][i].second;
		if(visit[there]==0){
			visit[there]=1;
			value=max(value,vt+dp(there));
			
		}
	}
	return value;
}


void dfs(int n){
	
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i].first;
		if(visit[there]==0){
			visit[there]=1;
			d[there]=d[n]+m[n][i].second;
			if(dis<d[there]){
				st=there;
				dis=d[there];
			}
			dfs(there);
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
	m=vector<vector<pair<int,int>>>(n+1);
	visit=vector<int>(n+1,0);
	d=vector<int>(n+1,0);
	for(int i=0;i<n-1;i++){
		int a,b,v;
		cin>>a>>b>>v;
		m[a].push_back(make_pair(b,v));
		m[b].push_back(make_pair(a,v));
	}
	dis=0;
	visit[1]=1;
	dfs(1);
	
	visit=vector<int>(n+1,0);
	d=vector<int>(n+1,0);
	
	/*
	dis=0;
	visit[st]=1;
	dfs(st);
	*/
	visit[st]=1;
	cout<<dp(st)<<'\n';
	
}