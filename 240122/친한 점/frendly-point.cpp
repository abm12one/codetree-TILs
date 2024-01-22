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
	
	int n,m;
	cin>>n>>m;
	set<pair<int,int>>s;
	
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		s.insert(make_pair(x,y));
		
	}
	for(int i=0;i<m;i++){
		int x,y;
		cin>>x>>y;
		if(s.lower_bound(make_pair(x,y))==s.end()){
			cout<<-1<<' '<<-1<<'\n';
		}
		else{
			cout<<s.lower_bound(make_pair(x,y))->first<<' '<<s.lower_bound(make_pair(x,y))->second<<'\n';
		}   
	}
	
	
}