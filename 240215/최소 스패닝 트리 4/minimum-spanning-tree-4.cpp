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
vector<int>edge;
typedef struct{
	int value;
	int st;
	int ed;
	
}node;

bool compare(node n1,node n2){
	return n1.value<n2.value;
}

vector<node>arr;




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
	
	int n,m;
	cin>>n>>m;
	p=vector<int>(n+1);
	v=vector<int>(n+1,1);
	edge=vector<int>(n+1);
	for(int i=0;i<n+1;i++){
		p[i]=i;
	}
	
	
	for(int i=1;i<=n;i++){
		char temp;
		cin>>temp;
		if(temp=='a'){
			edge[i]=0;
		}
		else{
			edge[i]=1;
		}
	}
	
	
	
	for(int i=0;i<m;i++){
		int a,b,d;
		cin>>a>>b>>d;
		arr.push_back(node{d,a,b});
		
	}
	int sum=0;
	
	sort(arr.begin(),arr.end(),compare);
	for(int i=0;i<m;i++){
		int nv=arr[i].value;
		int ns=arr[i].st;
		int ne=arr[i].ed;
		if(edge[ns]==edge[ne]){
			continue;
		}
		
		if(find(ns)==find(ne)){
			continue;
		}
		uset(ns,ne);
		sum+=nv;
	}
	if(v[find(1)]==n){
		cout<<sum<<'\n';
	}	
	else {
		cout<<-1<<'\n';
	}
	
}