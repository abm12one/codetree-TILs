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
int mdis;
int mnum;
int st;
vector<int>visit;
vector<int>dis;
vector<int>dnum;

void dfs(int n){
	
	visit[n]=1;
	
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i].first;
		if(visit[there]==0){
			
			dis[there]=dis[n]+m[n][i].second;
			dnum[there]=dnum[n]+1;
			if(mnum==dnum[there]){
				if(mdis>dis[there]){
					mdis=dis[there];
					st=there;
				}
			}
			
			else if(mnum<dnum[there]){
				mnum=dnum[there];
				mdis=dis[there];
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
	int n,d;
	cin>>n>>d;
	st=0;
	mdis=0;
	mnum=0;
	m=vector<vector<pair<int,int>>>(n+1);
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	dnum=vector<int>(n+1,0);
	
	for(int i=0;i<n-1;i++){
		int a,b,v;
		cin>>a>>b>>v;
		m[a].push_back(make_pair(b,v));
		m[b].push_back(make_pair(a,v));
		
	}
	
	dfs(1);
	
	
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	dnum=vector<int>(n+1,0);
	
	dfs(st);
	
	int ans=mdis/d;
	if(mdis%d!=0){
		ans++;
	}
	cout<<ans<<'\n';
	
}