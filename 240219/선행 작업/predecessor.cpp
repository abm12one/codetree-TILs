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

vector<int>t;
vector<int>cache;
vector<vector<int>>pre;

int dp(int now){
	
	int &ret=cache[now];
	
	if(ret!=-1){
		return ret;
	}
	
	ret=0;
	
	for(int i=0;i<pre[now].size();i++){
		int p=pre[now][i];
		ret=max(ret,dp(p));
	}
	
	ret+=t[now];
	
	return ret;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	t=vector<int>(n+1);
	cache=vector<int>(n+1,-1);
	pre=vector<vector<int>>(n+1);
	for(int i=1;i<n+1;i++){
		
		int rep;
		cin>>t[i];
		cin>>rep;
		
		for(int j=0;j<rep;j++){
			int temp;
			cin>>temp;
			pre[i].push_back(temp);
		}
		
	}
	
	int ans=0;
	
	for(int i=1;i<n+1;i++){
		ans=max(ans,dp(i));
	}

	cout<<ans<<'\n';
	
}