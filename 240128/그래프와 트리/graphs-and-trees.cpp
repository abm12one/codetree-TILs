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
	if(p[a]==0)return 0;
	
	if(p[a]==a){
		return p[a];
	}
	return p[a]=find(p[a]);
}

int uset(int a,int b){
	
	int fa=find(a);
	int fb=find(b);
	if(fa==0){
		if(fb==0){
			return 0;
		}
		else{
			p[fb]=0;
			return 0;
		}
		
	}
	
	else if(fb==0){
		p[fa]=0;
		return 0;
	}
	
	if(fa==fb){
		p[fa]=0;
		p[fb]=0;
		return 0;
	}
	
	p[fa]=fb;
	return 1;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k;
	cin>>n>>k;
	p=vector<int>(501);
	for(int i=0;i<n+1;i++){
		p[i]=i;
	}
	for(int i=0;i<k;i++){
		int a,b;
		cin>>a>>b;
		uset(a,b);
		
	}
	int sum=0;
	for(int i=1;i<n+1;i++){
		if(p[i]==i){
			sum++;
		}
	}
	cout<<sum<<'\n';
	
}