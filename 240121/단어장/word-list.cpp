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

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	map<string,int>m;
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string temp;
		cin>>temp;
		
		m[temp]++;
	}
	for(map<string,int>::iterator it=m.begin();it!=m.end();it++){
		cout<<it->first<<' '<<it->second<<"\n";
	}
	
}