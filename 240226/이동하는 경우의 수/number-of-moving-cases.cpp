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

int cnt;
typedef struct{
	int dest;
	int dis;
}node;

vector<vector<node>>map;
vector<int>cache;

int dp(int n){
	int &ret=cache[n];
	if(ret!=-1){
		return ret;
	}
	ret=0;
	int mmax=0;
	for(int i=0;i<map[n].size();i++){
		int p=map[n][i].dest;
		int d=map[n][i].dis;
		mmax=max(mmax,dp(p)+d);

	}
	return ret=mmax;
}


void sol(int n){

	for(int i=0;i<map[n].size();i++){
		int pre=map[n][i].dest;
		int d=map[n][i].dis;
		if(dp(n)==dp(pre)+d){
			cnt++;
			sol(pre);
		}
	}


}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,m;
	cin>>n>>m;
	
	map=vector<vector<node>>(n+1);
	cache=vector<int>(n+1,-1);
	cnt=0;

	for(int i=0;i<m;i++){
		int a,b,d;
		cin>>a>>b>>d;
		map[b].push_back(node{a,d});

	}

	cout<<dp(n)<<' ';

	sol(n);
	cout<<cnt<<"\n";


}