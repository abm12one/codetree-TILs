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

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	unordered_set<int>s;
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		
		s.insert(t);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		if(s.find(temp)==s.end()){
			cout<<'0'<<'\n';
		}
		else{
			cout<<'1'<<'\n';
		}
		
	}
	

}