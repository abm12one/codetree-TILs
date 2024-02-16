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

typedef struct{
	int st;
	int ed;
	
}node;
/*
bool compare(node n1,node n2){
	return n1.value<n2.value;
}
*/
vector<node>oarr;
vector<node>zarr;
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
	
	int n,m;
	cin>>n>>m;
	p=vector<int>(n+1);
	for(int i=0;i<n+1;i++){
		p[i]=i;
	}
	int on=0;
	int zn=0;
	for(int i=0;i<m;i++){
		int a,b,d;
		cin>>a>>b>>d;
		if(d==1){
			oarr.push_back(node{a,b});
			on++;
		}
		else{
			zarr.push_back(node{a,b});
			zn++;
		}
		
	}
	int en=0;
	int mmin=0;
	int mmax=0;
	for(int i=0;i<oarr.size();i++){
		if(uset(oarr[i].st,oarr[i].ed)==0)continue;
		en++;
		
	}
	if(en==n-1){
		mmin=0;
	}	
	else{
		mmin=pow(n-1-en,2);
	}
	
	for(int i=0;i<n+1;i++){
		p[i]=i;
	}
	for(int i=0;i<zarr.size();i++){
		if(uset(zarr[i].st,zarr[i].ed)==0)continue;
		en++;
		
	}
	if(en>=n-1){
		mmax=pow(n-1,2);
	}	
	else{
		mmin=pow(en,2);
	}

	
	
	cout<<mmax-mmin<<"\n";
}