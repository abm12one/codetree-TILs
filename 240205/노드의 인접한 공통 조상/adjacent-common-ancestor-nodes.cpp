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
vector<int>d;
vector<int>p;
vector<vector<int>>m;
void dfs(int n){
	
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i];
		
		d[there]=d[n]+1;
		
		dfs(there);
	}
	
	
}

int sol(int a,int b){

	while(d[a]!=d[b]){
		if(d[a]>d[b]){
			a=p[a];
			
		}
		else{
			b=p[b];
		}
		
	}
	
	
	while(a!=b){
		
		a=p[a];
		b=p[b];
		
	}
	
	return a;
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	visit=vector<int>(n+1);
	d=vector<int>(n+1);
	p=vector<int>(n+1);
	m=vector<vector<int>>(n+1);
	
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		p[b]=a;
		visit[b]=1;
	}
	
	int root;
	for(int i=1;i<n+1;i++){
		if(visit[i]==0){
			root=i;
			break;
		}
	}
	
	d[root]=1;
	dfs(root);
	
	int s,e;
	cin>>s>>e;
	cout<<sol(s,e);
	
	
}