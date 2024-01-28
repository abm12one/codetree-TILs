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
vector<vector<pair<int,int>>>m;
vector<int>visit;
vector<int>dis;
int ans;
int st;
int mnum;
int n;


void dfs(int now){
	visit[now]=1;
	for(int i=0;i<m[now].size();i++){
		int there=m[now][i].first;
		if(visit[there]==0){
			dis[there]=dis[now]+m[now][i].second;
			if(mnum<dis[there]){
				mnum=dis[there];
				st=there;
			}
			dfs(there);
			
		}
	}
	return;
}

int solve(int i,int j){
	int f,s;
	int ret=0;
	int there=m[i][j].first;
	int d=m[i][j].second;
	//1
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	st=0;
	mnum=0;
	visit[there]=1;
	dfs(i);
	if(st!=0){
		f=st;	
	}
	else{
		f=i;
	}
	
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	st=0;
	mnum=0;
	visit[there]=1;
	dfs(f);
	ret+=mnum;
	
	
	
	//2
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	st=0;
	mnum=0;
	visit[i]=1;
	dfs(there);
	
	if(st!=0){
		s=st;	
	}
	else{
		s=there;
	}
	
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	st=0;
	mnum=0;
	visit[i]=1;
	dfs(s);
	ret+=mnum;
	
	
	
	ret+=d;

	return ret;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	ans=0;
	
	cin>>n;
	m=vector<vector<pair<int,int>>>(n+1);
	visit=vector<int>(n+1);
	dis=vector<int>(n+1);
	
	for(int i=0;i<n-1;i++){
		int a,b,v;
		cin>>a>>b>>v;
		m[a].push_back(make_pair(b,v));
		m[b].push_back(make_pair(a,v));
	}
	
	dfs(1);
	int f=st;
	
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	mnum=0;
	dfs(f);
	ans=max(ans,mnum);
	
	for(int i=1;i<n+1;i++){
		for(int j=0;j<m[i].size();j++){
			ans=max(ans,solve(i,j));
		}
	}
	cout<<ans<<'\n';
	
	
	
}