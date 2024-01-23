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
	set<int>s;
	
	for(int i=0;i<n;i++){
		
		int t;
		cin>>t;
		s.insert(t);
		
	}
	for(int i=0;i<m;i++){
		int t;
		cin>>t;
		auto it=s.upper_bound(t);
		if(it==s.begin()){
			cout<<-1<<'\n';
		}
		else{
			it--;
			cout<<*it<<'\n';
			s.erase(it);
		}
	}
	
}