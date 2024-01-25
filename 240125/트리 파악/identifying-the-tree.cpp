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
int sum;
vector<vector<int>>m;
vector<int>visit;
vector<int>dis;
void dfs(int n){
	int flag=0;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i];
		if(visit[there]==0){
			flag=1;
			visit[there]=1;
			dis[there]=dis[n]+1;
			dfs(there);
		}
		
	}
	if(flag==0){
		sum+=dis[n];
	}
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	sum=0;
	m=vector<vector<int>>(n+1);
	visit=vector<int>(n+1,0);
	dis=vector<int>(n+1,0);
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	dis[1]=0;
	visit[1]=1;
	dfs(1);
	
	if(sum%2==0){
		cout<<0<<'\n';
	}
	else{
		cout<<1<<'\n';
	}
	
	
}