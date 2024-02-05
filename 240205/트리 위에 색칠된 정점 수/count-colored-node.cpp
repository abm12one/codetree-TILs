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
vector<int>d;
vector<int>v;
vector<int>color;
vector<vector<int>>p;

int maxh;
int n;

void dfs(int n){
	visit[n]=1;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i];
		
		if(visit[there]==1)continue;
		
		if(color[there]==1){
			v[there]=v[n]+1;
		}
		else{
			v[there]=v[n];
		}
		
		p[0][there]=n;
		d[there]=d[n]+1;
		dfs(there);
	}
}

void sett(){
	
	for(int h=1;h<=maxh;h++){
		for(int now=1;now<n+1;now++){
			p[h][now]=p[h-1][p[h-1][now]];
		}
	}
	
}



int find(int s, int e){
	int a,b;
	a=s;
	b=e;
	
	if(d[e]>d[s]){
		a=e;
		b=s;
	}
	
	for(int i=maxh;i>=0;i--){
		if(d[a]-d[b]>=(1<<i)){
			a=p[i][a];
		}
	}
	
	if(a==b){
		return a;
	}
	
	for(int i=maxh;i>=0;i--){
		
		if(p[i][a]!=p[i][b]){
			a=p[i][a];
			b=p[i][b];
			
		}
	}
	
	
	return p[0][a];
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n;
	
	m=vector<vector<int>>(n+1);
	visit=vector<int>(n+1);
	d=vector<int>(n+1);
	p=vector<vector<int>>(31,vector<int>(n+1));
	color=vector<int>(n+1);
	v=vector<int>(n+1);
	
	maxh=30;
	
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
		
	}
	
	int k;
	cin>>k;
	for(int i=0;i<k;i++){
		
		int a;
		cin>>a;
		color[a]=1;
		
	}
	
	v[1]=color[1];
	d[1]=1;
	p[0][1]=1;
	dfs(1);
	
	
	sett();
	
	
	int q;
	cin>>q;
	

	for(int i=0;i<q;i++){
		int s,e; 
		cin>>s>>e; 
		int res=find(s,e);
		cout<<v[s]+v[e]-2*v[res]+color[res]<<'\n';
	}
	
	
}