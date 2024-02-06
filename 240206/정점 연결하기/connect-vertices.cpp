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
	
	if(fb<fa){
		p[fa]=fb;
		
	}
	else{
		p[fb]=fa;
	}
	
	return ;
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	
	p=vector<int>(n+1);
	for(int i=0;i<n+1;i++){
		p[i]=i;
	}
	
	for(int i=0;i<n-2;i++){
		
		int a,b;
		cin>>a>>b;
		uset(a,b);
	}
	
	vector<int>ans;
	ans.push_back(find(1));
	for(int i=1;i<n+1;i++){
		if(find(i)!=find(1)){
			ans.push_back(find(i));
			break;
		}
	}
	sort(ans.begin(),ans.end());
	cout<<ans[0]<<' '<<ans[1]<<'\n';
	
}