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
vector<int>arr;
vector<int>visit;

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
	
	if(arr[fa]<arr[fb]){
		p[fb]=fa;
	}
	else{
		p[fa]=fb;
	}
	
	return ;
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m,k;
	cin>>n>>m>>k;
	
	p=vector<int>(n+1);
	arr=vector<int>(n+1);
	visit=vector<int>(n+1);
	for(int i=0;i<n+1;i++){
		p[i]=i;
	}
	
	for(int i=1;i<n+1;i++){
		cin>>arr[i];
	}
	
	for(int i=0;i<m;i++){
		
		int a,b;
		cin>>a>>b;
		uset(a,b);
		
	}
	vector<int>ans;
	
	for(int i=1;i<n+1;i++){
		int fi=find(i);
		if(visit[fi]==0){
			visit[fi]=1;
			ans.push_back(arr[fi]);
		}
	}
	sort(ans.begin(),ans.end());
	
	int sum=0;
	for(int i=1;i<ans.size();i++){
		
		sum+=ans[i]+ans[0];
		
	}
	if(sum>k){
		cout<<"NO"<<"\n";
	}
	else{
		cout<<sum<<'\n';
	}
	
}