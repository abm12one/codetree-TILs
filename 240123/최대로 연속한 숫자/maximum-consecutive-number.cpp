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
set<tuple<int,int,int>>s;


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	set<int>num;
	set<tuple<int,int,int>>s;
	num.insert(-1);
	num.insert(n+1);
	s.insert(make_tuple(n+1,-1,n+1));
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		auto it=num.lower_bound(t);
		int r=*it;
		it--;
		int l=*it;
		
		s.erase(make_tuple(r-l-1,l,r));
		s.insert(make_tuple(r-t-1,t,r));
		s.insert(make_tuple(t-l-1,l,t));
		num.insert(t);
		tuple<int,int,int> now=*s.rbegin();
		
		cout<<get<0>(now)<<'\n';
	}
	
	
}