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

vector<vector<int>>list;
vector<int>p;

void dfs(int n){
	
	
	for(int i=0;i<list[n].size();i++){
		int there=list[n][i];
		p[there]+=p[n];
		dfs(there);
	}
	return;
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	list=vector<vector<int>>(n+1);
	p=vector<int>(n+1);
	
	for(int i=1;i<=n;i++){
		int pa;
		cin>>pa;
		if(pa==-1)continue;
		list[pa].push_back(i);
	}
	
	for(int i=0;i<m;i++){
		int a,w;
		cin>>a>>w;
		
		p[a]+=w;
		
	}
	
	dfs(1);
	
	for(int i=1;i<=n;i++){
		cout<<p[i]<<' ';
	}
	
	
}