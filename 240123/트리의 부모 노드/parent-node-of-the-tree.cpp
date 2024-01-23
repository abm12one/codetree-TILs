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
vector<int>pa;
int n;
void dfs(int r){
	
	for(int i=0;i<m[r].size();i++){
		int next=m[r][i];
		if(visit[next]==0){
			pa[next]=r;
			visit[next]=1;
			dfs(next);
		}
		
	}
	return;

}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n;
	visit=vector<int>(n+1,0);
	pa=vector<int>(n+1,0);
	m=vector<vector<int>>(n+1);
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	int root=1;
	visit[root]=1;
	dfs(root);
	
	for(int i=2;i<n+1;i++){
		cout<<pa[i]<<'\n';
	}
	
}