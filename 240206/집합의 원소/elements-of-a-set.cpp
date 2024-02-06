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
		int t,a,b;
		cin>>t>>a>>b;
		if(t==0){
			uset(a,b);
		}
		else{
			int fa=find(a);
			int fb=find(b);
			if(fb==fa){
				cout<<1<<'\n';
			}
			else{
				cout<<0<<'\n';
			}
		}
		
	}
	
	
}