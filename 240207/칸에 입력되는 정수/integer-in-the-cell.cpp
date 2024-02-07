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
	
	int n,m;
	cin>>n;
	cin>>m;
	
	p=vector<int>(n+1);
	
	for(int i=1;i<n+1;i++){
		p[i]=i;
	}
	
	int ans;
	for(int i=1;i<=m;i++){
		int k;
		cin>>k;
		int fk=find(k);
		if(fk==0){
			ans=i-1;
			break;
		}
		p[fk]=find(fk-1);
		
		
	}
	cout<<ans<<'\n';
	
}