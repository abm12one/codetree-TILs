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

vector<int>p;
vector<int>visit;
vector<int>snum;

int find(int a){
	if(p[a]==a){
		return p[a];
	}
	
	return p[a]=find(p[a]);
}

int uset(int a,int b){
	
	int fa=find(a);
	int fb=find(b);
	if(fa==fb){
		return 1;
	}
	
	if(snum[fb]>snum[fa]){
		p[fa]=fb;
		snum[fb]+=snum[fa];
		
	}
	else{
		p[fb]=fa;
		snum[fa]+=snum[fb];
	}
	
	return 0;
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	p=vector<int>(n+1);
	snum=vector<int>(n+1);
	visit=vector<int>(n+1);
	
	for(int i=0;i<n+1;i++){
		p[i]=i;
		snum[i]=1;
	}
	
	for(int i=0;i<m;i++){
		
		int a,b;
		cin>>a>>b;
		uset(a,b);
		
	}
	
	for(int i=1;i<n+1;i++){
		visit[find(i)]++;
	}
	
	vector<pair<int,int>>arr;
	
	for(int i=1;i<n+1;i++){
		if(visit[i]==0)continue;
		
		arr.push_back(make_pair(snum[i],i));
		
		
	}
	sort(arr.begin(),arr.end());
	
	int s,e,k;
	cin>>s>>e>>k;
	int now=1;
	int ans=snum[find(s)];

	for(int i=arr.size()-1;i>=0;i--){

		if(now<=k&&i!=find(s)&&i!=find(e)){
			ans+=snum[find(i)];
			now++;
		}
		
		
	}
	cout<<ans<<'\n';
	
}