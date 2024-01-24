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
vector<int>hasr;

void dfs(int n){
	for(int i=0;i<m[n].size();i++){
		int next=m[n][i];
		if(visit[next]==0){
			visit[next]=1;
			dfs(next);
		}
		
	}
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	m=vector<vector<int>>(n+2);
	visit=vector<int>(n+2,0);
	hasr=vector<int>(n+2,0);
	
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		if(hasr[b]==1){
			cout<<0<<'\n';
			return 0;
		}
		m[a].push_back(b);
		hasr[b]++;
	}
	
	
	
	for(int i=1;i<=n+1;i++){
		if(visit[i]==0){
			dfs(i);
		}
		
	}
	int sum=0;
	for(int i=1;i<n+2;i++){
		if(visit[i]==1){
			sum++;
		}
	}
	if(sum==n){
		cout<<1<<'\n';
		
	}
	else{
		cout<<0<<'\n';
	}
}