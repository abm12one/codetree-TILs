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
vector<int>visit;
vector<int>way;
int cent;

void dfs(int n){
	int sum=0;
	visit[n]=1;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i];
		if(visit[there]==0){
			sum++;
			dfs(there);
		}
		
	}
	if(sum>1){
		cent=n;
		return;
	}
	else if(sum==0){
		cent=n;
		return;
	}
	
}

int sol(int n){
	
	int &ret=way[n];
	
	if(ret!=-1){
		return ret;
	}
	
	visit[n]=1;
	
	ret=1;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i];
		if(visit[there]==0){
			ret+=sol(there);
		}
	}	
	return ret;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,r;
	cin>>n>>r;
	
	m=vector<vector<int>>(n+1);
	visit=vector<int>(n+1);
	way=vector<int>(n+1,-1);
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	
	dfs(r);
	
	visit=vector<int>(n+1,0);
	
	sol(cent);
	
	
	vector<int>ans;
	for(int i=0;i<m[cent].size();i++){
		int there=m[cent][i];
		ans.push_back(way[there]);;
	}
	sort(ans.begin(),ans.end());
	cout<<ans[ans.size()-1]-ans[0];
}