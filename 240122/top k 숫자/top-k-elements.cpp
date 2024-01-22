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
	
	int n,k;
	cin>>n>>k;
	set<int>s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		s.insert(t);
	}
	set<int>::iterator it=s.end();
	it--;
	for(int i=0;i<k;i++){
		cout<<*it<<' ';
		it--;
	}
	
	
}