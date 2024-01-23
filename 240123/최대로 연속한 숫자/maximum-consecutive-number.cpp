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
int n,m;
set<int>s;

int find(set<int>&s){
	
	auto st=s.begin();
	auto ed=st;
	ed++;
	int mnum=0;
	
	while(ed!=s.end()){
		mnum=max(mnum,*ed-*st-1);
		ed++;
		st++;
	}
	return mnum;
	
}
int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	
	cin>>n>>m;
	s.insert(-1);
	s.insert(n+1);
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		s.insert(t);
		int dis=find(s);
		cout<<dis<<'\n';
		
	}
	
	
}