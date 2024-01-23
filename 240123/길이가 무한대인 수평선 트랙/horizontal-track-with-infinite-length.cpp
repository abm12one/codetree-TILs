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
	
	int n,t;
	cin>>n>>t;
	set<int>s;
	int sum=0;
	for(int i=0;i<n;i++){
		int st,v;
		cin>>st>>v;
		int ed=st+v*t;
		while(1){
			auto it=s.lower_bound(ed);
			if(it==s.end()){
				break;
			}
			s.erase(*it);
		}
		s.insert(ed);
	}
	cout<<s.size()<<'\n';
	
}