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

int ans;
vector<int>arr;
vector<int>cache;
vector<int>visit;
vector<vector<int>>m;

int dfs(int n){
	int &ret=cache[n];
	
	if(ret!=-1){
		return ret;
	}
	
	ret=0;
	int sum=0;
	visit[n]=1;
	
	for(int i=0;i<m[n].size();i++){
		
		int there=m[n][i];
		if(visit[there]==0){
			int dt=dfs(there);
			ret=max(ret,dt);
			sum+=dt;
		}
		
	}
	sum+=arr[n];
	ret+=arr[n];
	ans=max(ans,sum);
	//cout<<n<<' '<<ret<<' '<<sum<<'\n';
	return ret;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	ans=0;
	arr=vector<int>(n+1);
	cache=vector<int>(n+1,-1);
	visit=vector<int>(n+1);
	m=vector<vector<int>>(n+1);
	
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i];
	}
	dfs(1);
	cout<<ans<<'\n';
}