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

vector<vector<int>>map;
vector<int>cache;

int dp(int n){
		
	int &ret=cache[n];
	if(ret!=-1){
		return ret;
	}
	ret=1;
	
	int mmax=-1;
	int cnt=1;
	
	for(int i=0;i<map[n].size();i++){
		int p=map[n][i];
		int cp=dp(p);
		if(cp>mmax){
			mmax=cp;
			cnt=1;
		}
		else if(cp==mmax){
			cnt++;
		}
	}
	
	if(cnt>1){
		return ret=mmax+1;
	}
	if(mmax==-1){
		return ret=1;
	}
	return ret=mmax;
	
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	map=vector<vector<int>>(n+1);
	cache=vector<int>(n+1,-1);
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		map[b].push_back(a);
		
	}
	
	int ans=0;
	for(int i=1;i<n+1;i++){
		ans=max(ans,dp(i));
		
	}
	cout<<ans<<'\n';
	
	
}