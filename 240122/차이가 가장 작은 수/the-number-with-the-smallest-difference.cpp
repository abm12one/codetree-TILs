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
	int sum=0;
	cin>>n>>m;
	set<int>s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.insert(t);
	}
	
	int ans=987654321;
	for(set<int>::iterator st=s.begin();st!=s.end();st++){
		set<int>::iterator it=s.lower_bound(*st+m);
		if(it!=s.end()){
			
			ans=min(ans,*it-*st);
		}
		
	}
	if(ans==987654321){
		cout<<-1<<'\n';
	}
	else{
		cout<<ans<<'\n';
	}
	
}