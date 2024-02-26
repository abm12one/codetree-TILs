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
//#include< unordered_map>
//#include< map>
//#include < unordered_set>
//#include< set>

using namespace std;

vector<vector<int>>map;
vector<int>cache;
vector<int>arr;

int dp(int n){
	
	int &ret=cache[n];
	if(ret!=-1){
		return ret;
	}
	
	ret=0;
	
	int mmax=0;
	for(int i=0;i<map[n].size();i++){
		
		int p=map[n][i];
		if(dp(p)>mmax){
			mmax=dp(p);
			arr[n]=p;
		}
		
	}
	if(mmax==0){
		return ret;
	}
	return ret=mmax+1;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	map=vector<vector<int>>(100001);
	cache=vector<int>(100001,-1);
	arr=vector<int>(100001,0);
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		map[a].push_back(b);
		
	}
	
	for(int i=0;i<100001;i++){
		sort(map[i].begin(),map[i].end());
	}
	
	cache[n]=1;
	
	if(dp(1)==0){
		cout<<-1<<'\n';
		return 0;
	}
	/*
	for(int i=0;i<n+1;i++){
		cout<<arr[i]<<'\n';
	}
	for(int i=0;i<n+1;i++){
		cout<<cache[i]<<'\n';
	}
	*/

	int now=1;
	vector<int>r;
	while(1){
		if(arr[now]==0)break;
		r.push_back(now);
		now=arr[now];
	}
    r.push_back(n);

	cout<<r.size()<<'\n';
	
	for(int i=0;i<r.size();i++){
		cout<<r[i]<<' ';
	}	
	
}