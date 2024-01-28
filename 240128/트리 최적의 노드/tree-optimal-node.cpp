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


int mnum;
int st;
vector<vector<int>>arr;
vector<int>visit;
vector<int>dis;
void dfs(int n){
	visit[n]=1;
	
	
	for(int i=0;i<arr[n].size();i++){
		int there=arr[n][i];
		
		if(visit[there]==0){
			
			dis[there]=dis[n]+1;
			if(dis[there]>mnum){
				mnum=dis[there];
				st=there;
				
			}
			dfs(there);
			
		}
		
	}
	
	return;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	
	mnum=0;
	arr=vector<vector<int>>(n+1);
	visit=vector<int>(n+1);
	dis=vector<int>(n+1);
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		arr[a].push_back(b);
		arr[b].push_back(a);
		
	}
	
	dfs(1);
	
	
	
	dis=vector<int>(n+1,0);
	visit=vector<int>(n+1,0);
	
	visit[st]=1;
	dfs(st);
	cout<<(mnum+1)/2<<'\n';
}