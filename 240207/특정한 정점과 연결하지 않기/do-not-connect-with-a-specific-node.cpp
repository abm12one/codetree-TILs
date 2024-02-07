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

void uset(int a,int b){
	
	int fa=find(a);
	int fb=find(b);
	if(fa==fb){
		return ;
	}
	
	p[fa]=fb;
	snum[fb]+=snum[fa];
	
	return ;
	
	
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
	vector<int>arr;
	for(int i=1;i<n+1;i++){
		p[i]=i;
		snum[i]=1;
	}
	
	for(int i=0;i<m;i++){
		
		int a,b;
		cin>>a>>b;
		uset(a,b);
		
	}
	
	
	
	int s,e,k;
	cin>>s>>e>>k;
	
	int fs=find(s);
	int fe=find(e);
	for(int i=1;i<n+1;i++){
		int fi=find(i);
		if(fi==fs||fi==fe)continue;
		
		if(visit[fi]==0){
			visit[fi]=1;
			arr.push_back(snum[fi]);
		}
		
		
	}
	
	sort(arr.begin(),arr.end(),greater());
	
	int res=snum[fs];
	int nk=min(k,(int)arr.size());
	for(int i=0;i<nk;i++){
		res+=arr[i];
	}
	cout<<res<<'\n';
	
	
}