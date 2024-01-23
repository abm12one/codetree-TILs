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


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	set<pair<int,int>>s;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
	
		int x,y;
		cin>>x>>y;
		s.insert(make_pair(x,y));
		
	}
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		if(s.lower_bound(make_pair(t,0))==s.end()){
			cout<<-1<<' '<<-1<<'\n';
		}
		else{
			auto it=s.lower_bound(make_pair(t,0));
			s.erase(*it);
			cout<<it->first<<' '<<it->second<<'\n';
		}
		
	}
	
	
}