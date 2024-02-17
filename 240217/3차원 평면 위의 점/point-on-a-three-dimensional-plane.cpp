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
	int x,y,z,id;
}node;

vector<node>narr;
vector<edge>earr;
vector<int>p;

bool compare(edge e1,edge e2){
	return e1.value<e2.value;
}

bool cmpx(node n1,node n2){
	return n1.x<n2.x;
}
bool cmpy(node n1,node n2){
	return n1.y<n2.y;
}
bool cmpz(node n1,node n2){
	return n1.z<n2.z;
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
		narr.push_back(node{x,y,z,i});
	}
	
	sort(narr.begin(),narr.end(),cmpx);
	for(int i=0;i<narr.size()-1;i++){
		int v=abs(narr[i].x-narr[i+1].x);
		int s=narr[i].id;
		int e=narr[i+1].id;
		earr.push_back(edge{v,s,e});
	}
	
	sort(narr.begin(),narr.end(),cmpy);
	for(int i=0;i<narr.size()-1;i++){
		int v=abs(narr[i].y-narr[i+1].y);
		int s=narr[i].id;
		int e=narr[i+1].id;
		earr.push_back(edge{v,s,e});
	}
	
	sort(narr.begin(),narr.end(),cmpz);
	for(int i=0;i<narr.size()-1;i++){
		int v=abs(narr[i].z-narr[i+1].z);
		int s=narr[i].id;
		int e=narr[i+1].id;
		earr.push_back(edge{v,s,e});
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