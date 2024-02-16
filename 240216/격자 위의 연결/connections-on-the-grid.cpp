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
	p=vector<int>(m*n+1);
	
	for(int i=0;i<m*n+1;i++){
		p[i]=i;
		
	}
	
	for(int i=0;i<n;i++){
		int st=m*i+1;
		for(int j=0;j<m-1;j++){
			int d;
			cin>>d;
			arr.push_back(node{d,st,st+1});
			st++;
		}
		
	}
	for(int i=0;i<n-1;i++){
		int st=m*i+1;
		for(int j=0;j<m;j++){
			int d;
			cin>>d;
			arr.push_back(node{d,st,st+m});
			st++;
		}
		
	}
	
	sort(arr.begin(),arr.end(),compare);
	int sum=0;
	for(int i=0;i<arr.size();i++){
		if(uset(arr[i].st,arr[i].ed)==0)continue;
		sum+=arr[i].value;
	}
	cout<<sum<<'\n';
	
}