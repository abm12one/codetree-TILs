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
vector<vector<int>>way;

void sol(int n){
	visit[n]=1;
	int flag=0;
	for(int i=0;i<m[n].size();i++){
		
		int there=m[n][i];
		if(visit[there]==0){
			flag=1;
			sol(there);
			way[n][0]+=way[there][1];
			way[n][1]+=min(way[there][0],way[there][1])+1;
		}
		
	}
	if(flag==0){
		way[n][0]=0;
		way[n][1]=1;
	}
	return;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	int n;
	cin>>n;
	
	m=vector<vector<int>>(n+1);
	visit=vector<int>(n+1,0);
	way=vector<vector<int>>(n+1,vector<int>(2));
	
	for(int i=0;i<n-1;i++){
		
		int a,b;
		cin>>a>>b;
		m[a].push_back(b);
		m[b].push_back(a);
		
	}
	
	sol(1);
	cout<<min(way[1][0],way[1][1]);
	
}