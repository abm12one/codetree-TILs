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
vector<int>v;
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
	v[fb]+=v[fa];
	return ;
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	p=vector<int>(100001);
	v=vector<int>(100001,1);
	for(int i=0;i<100001;i++){
		p[i]=i;
		
	}
	
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		uset(a,b);
		
		
		cout<<v[find(a)]<<'\n';
		
	}
	
	
	return 0;
	
}