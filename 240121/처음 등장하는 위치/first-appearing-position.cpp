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
	
	map<int,int>m;
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		if(m.count(temp)>0){
			continue;
		}
		m[temp]=i;
	}
	for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
		cout<<it->first<<' '<<it->second+1<<"\n";
	}
	
}