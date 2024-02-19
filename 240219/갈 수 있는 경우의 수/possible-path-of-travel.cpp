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
vector<vector<int>>pre;

int dp(int now){
	
	int &ret=cache[now];
	if(ret!=0&&ret!=-1){
		return ret;
	}
	ret=0;
	
	for(int i=0;i<pre[now].size();i++){
		int p=pre[now][i];
		ret+=dp(p);
		ret%=1000000007;
	}
	
	return ret;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	cache=vector<int>(n+1,-1);
	pre=vector<vector<int>>(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		pre[b].push_back(a);
		
	}
	cache[1]=1;
	cout<<dp(n)<<'\n';
	
}