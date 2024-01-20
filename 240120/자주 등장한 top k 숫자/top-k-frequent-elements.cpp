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
#include <unordered_map>

using namespace std;

typedef struct{
	int v;
	int rep;
}node;

vector<node>narr;

bool cmp(node n1,node n2){
	if(n1.rep==n2.rep){
		return n1.v>n2.v;
	}
	return n1.rep>n2.rep;
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	unordered_map<int,int>map;
	vector<int>arr(n);
	vector<int>visit(100001,0);
	for(int i=0;i<n;i++){
		cin>>arr[i];
		map[arr[i]]++;
	}
	for(int i=0;i<n;i++){
		if(visit[arr[i]]==0){
			narr.push_back(node{arr[i],map[arr[i]]});
			visit[arr[i]]=1;
		}
		
	}
	sort(narr.begin(),narr.end(),cmp);
	for(int i=0;i<m;i++){
		cout<<narr[i].v<<' ';
	}
}