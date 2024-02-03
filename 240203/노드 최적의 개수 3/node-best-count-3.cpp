#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
#include<string>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<limits.h>
#include<cassert>

using namespace std;
int g,h;
vector<int>visit;
vector<vector<int>>map;
int watched=0;
int unwatched=1;
int installed=2;
int cam;
int n;

int dfs(int here){
	
	visit[here]=1;
	int children[3]={0,0,0};
	
	for(int i=0;i<map[here].size();i++){
		int there=map[here][i];
		if(visit[there]==0){
			children[dfs(there)]++;
		}
	}
	
	if(children[unwatched]){
		//cout<<here<<"unwatched->installed'"<<'\n';
		cam++;
		return installed;
	}
	if(children[installed]){
		//cout<<here<<"watched"<<'\n';
		return watched;
	}
	//cout<<here<<"unwatched"<<'\n';
	return unwatched;
}

void solve(){
	for(int i=1;i<=n;i++){
		if(visit[i]==0&&dfs(i)==unwatched){
			cam++;
		}
	}	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
		
	cin>>n;
	visit=vector<int>(n+1,0);
	map=vector<vector<int>>(n+1);
	cam=0;
	for(int i=0;i<n-1;i++){
			
		int a,b;
		cin>>a>>b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
		
	solve();
	cout<<cam<<'\n';
		
	
	
}