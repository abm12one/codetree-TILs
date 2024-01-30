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
vector<int>cache;
vector<int>visit;
int dp(int n){
	visit[n]=1;
	int &ret=cache[n];
	if(ret!=-1){
		return ret;
	}
	ret=1;
	for(int i=0;i<m[n].size();i++){
		int there=m[n][i];
		if(visit[there]==0){
			ret+=dp(there);
		}
		
	}
	return ret;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,r,q;
	cin>>n>>r>>q;
	m=vector<vector<int>>(n+1);
	cache=vector<int>(n+1,-1);
	visit=vector<int>(n+1,0);
	for(int i=0;i<n-1;i++){
		
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	
	dp(r);
	
	for(int i=0;i<q;i++){
		int k;
		cin>>k;
		cout<<dp(k)<<'\n';
	}
	return 0;
}