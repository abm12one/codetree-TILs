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
		int temp;
		cin>>temp;
		s.insert(temp);
	}
	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		
		
		if(s.find(k)!=s.end()){
			if(s.lower_bound(k)!=s.end()){
				cout<<*s.lower_bound(k)<<'\n';
				continue;
			}
			else{
				cout<<k<<'\n';
				continue;
			}
		}
		if(s.lower_bound(k)!=s.end()){
			cout<<*s.lower_bound(k)<<'\n';
			continue;
		}
		else{
			cout<<-1<<"\n";
			continue;
		}
		
	}
	
}