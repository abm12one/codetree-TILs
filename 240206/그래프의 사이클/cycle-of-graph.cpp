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
	
	int flag=0;
	
	for(int i=1;i<=m;i++){
		
		int a,b;
		cin>>a>>b;
		if(uset(a,b)==1&&flag==0){
			flag=1;
			cout<<i<<"\n";
		}
	}
	if(flag==0){
		cout<<"happy"<<'\n';
	}
	
	
	
}