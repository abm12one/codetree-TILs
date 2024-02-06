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

typedef struct{
	int a,b,d;
}node;

vector<node>arr;

bool comp(node n1, node n2){
	
	return n1.d>n2.d;
	
}

vector<int>p;
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
	
	if(fb<fa){
		p[fa]=fb;
		
	}
	else{
		p[fb]=fa;
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
	for(int i=0;i<n+1;i++){
		p[i]=i;
	}
	
	int st,ed;
	cin>>st>>ed;
	
	for(int i=0;i<m;i++){
		int s,e,v;
		cin>>s>>e>>v;
		arr.push_back(node{s,e,v});
		
	}
	
	sort(arr.begin(),arr.end(),comp);
	

	for(int i=0;i<m;i++){
		int ns,ne,nv;
		ns=arr[i].a;
		ne=arr[i].b;
		nv=arr[i].d;
		uset(ns,ne);
		if(find(st)==find(ed)){
			cout<<nv<<"\n";
			break;
		}
		
	}
	
	
	
}