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
//#include <unordered_set>
//#include<set>

using namespace std;

vector<int>cache;
vector<vector<int>>map;

void dp(int now){
	
	for(int i=0;i<map[now].size();i++){
		int p=map[now][i];
		cache[p]+=cache[now];
		cache[p]%=1000000007;
		dp(p);
	}
	return;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	cache=vector<int>(n+1,0);
	map=vector<vector<int>>(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		map[a].push_back(b);
		
	}
	cache[1]=1;
	dp(1);
	cout<<cache[n]<<'\n';
	
}