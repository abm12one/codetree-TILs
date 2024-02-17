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
//#include<unordered_map>
//#include<map>
#include <unordered_set>
#include<set>

using namespace std;

typedef struct{
	int value;
	int st;
	int ed;
	
}edge;

typedef struct {
	int x,y,z;
}node;

vector<node>narr;
vector<edge>earr;
vector<int>p;

bool compare(edge e1,edge e2){
	return e1.value<e2.value;
}

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
	narr=vector<node>(n+1);
	p=vector<int>(n+1);
	
	for(int i=0;i<n+1;i++){	
		p[i]=i;
	}
	
	for(int i=1;i<=n;i++){
		int x,y,z;
		cin>>x>>y>>z;
		narr[i]=node{x,y,z};
	}
	
	for(int i=1;i<narr.size()-1;i++){
		for(int j=i+1;j<narr.size();j++){
			int dx=abs(narr[i].x-narr[j].x);
			int dy=abs(narr[i].y-narr[j].y);
			int dz=abs(narr[i].z-narr[j].z);
			int mmin=min(dx,min(dy,dz));
			earr.push_back(edge{mmin,i,j});
		}
	}
	
	sort(earr.begin(),earr.end(),compare);
	
	int sum=0;
	for(int i=0;i<earr.size();i++){
		int s=earr[i].st;
		int e=earr[i].ed;
		
		if(uset(s,e)==0)continue;
		sum+=earr[i].value;
		
	}
	
	cout<<sum<<'\n';
}