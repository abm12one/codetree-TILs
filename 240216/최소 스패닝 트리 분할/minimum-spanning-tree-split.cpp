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
	return ;
	
	
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
	
	for(int i=0;i<m;i++){
		int a,b,d;
		cin>>a>>b>>d;
		arr.push_back(node{d,a,b});
		
	}
	int sum=0;
	int temp;
	sort(arr.begin(),arr.end(),compare);
	for(int i=0;i<m;i++){
		int nv=arr[i].value;
		int ns=arr[i].st;
		int ne=arr[i].ed;
		
		if(find(ns)==find(ne)){
			continue;
		}
		uset(ns,ne);
		sum+=nv;
		temp=nv;
	}
			
	cout<<sum-temp<<'\n';
	
}