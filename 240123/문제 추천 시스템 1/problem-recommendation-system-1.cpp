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
	cin>>n;
	for(int i=0;i<n;i++){
		int p,l;
		cin>>p>>l;
		s.insert(make_pair(l,p));
		
	}
	cin>>m;
	for(int i=0;i<m;i++){
		string str;
		cin>>str;
		
		
		if(str=="ad"){
			
			int x,y;
			cin>>x>>y;
			s.insert(make_pair(y,x));
			
		}
		else if(str=="sv"){
			int x,y;
			cin>>x>>y;
			auto it=s.lower_bound(make_pair(y,x));
			s.erase(*it);
		
			
		}
		else if(str=="rc"){
			int t;
			cin>>t;
			if(t==1){
				cout<<s.rbegin()->second<<"\n";
			}
			if(t==-1){
				cout<<s.begin()->second<<"\n";
			}
		}
	}
	
}