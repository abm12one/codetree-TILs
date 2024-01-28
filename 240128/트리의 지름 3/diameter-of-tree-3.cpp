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
int st;
int mnum;
void dfs(int n){
	visit[n]=1;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i].first;
		if(visit[there]==0){
			dis[there]=dis[n]+m[n][i].second;
			if(mnum<dis[there]){
				mnum=dis[there];
				st=there;
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
	visit=vector<int>(n+1);
	dis=vector<int>(n+1);
	vector<int>ans;
	for(int i=0;i<n-1;i++){
		int a,b,v;
		cin>>a>>b>>v;
		m[a].push_back(make_pair(b,v));
		m[b].push_back(make_pair(a,v));
	}
	mnum=0;
	dfs(1);
	int f=st;
	
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	mnum=0;
	dfs(f);
	int s=st;
	ans.push_back(mnum);
	
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	mnum=0;
	visit[f]=1;
	dfs(s);
	ans.push_back(mnum);
	
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	mnum=0;
	visit[s]=1;
	dfs(f);
	ans.push_back(mnum);
	
	sort(ans.begin(),ans.end());
	cout<<ans[1]<<'\n';
	
}