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
vector<int>p;
vector<int>hasr;

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
		return 0;
	}
	
	p[fa]=fb;
	return 1;
	
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	p=vector<int>(10001);
	
	for(int i=1;i<10002;i++){
		p[i]=i;
	}
	
	m=vector<vector<int>>(10001);
	hasr=vector<int>(10001,0);
	
	for(int i=0;i<n;i++){
		int a,b;
		cin>>a>>b;
		
		
		if(hasr[b]==1){
			cout<<0<<'\n';
			return 0;
		}
		
		if(uset(a,b)==0){
			cout<<0<<'\n';
			return 0;
		}
		
		m[a].push_back(b);
		hasr[b]++;
	}
	int sum=0;
	for(int i=1;i<=10001;i++){
		if(hasr[i]==1){
			sum++;
		}
	}
	if(sum==n){
		cout<<1<<'\n';
	}
	else{
		cout<<0<<'\n';
	}
}