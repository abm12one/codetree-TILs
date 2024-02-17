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
//#include<unordered_map>
//#include<map>
#include <unordered_set>
#include<set>

using namespace std;
vector<vector<int>>map;
vector<int>visit;
vector<int>ans;
void dfs(int now){
	visit[now]=1;
	for(int i=0;i<map[now].size();i++){	
		int there=map[now][i];
		if(visit[there]==0){
			dfs(there);
		}
	}
	ans.push_back(now);
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	map=vector<vector<int>>(n+1);
	visit=vector<int>(n+1,0);
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		map[a].push_back(b);
	}
	
	for(int i=1;i<n+1;i++){
		if(visit[i]==0){
			dfs(i);
		}
	}
	
	reverse(ans.begin(),ans.end());
	
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}
	
	
}