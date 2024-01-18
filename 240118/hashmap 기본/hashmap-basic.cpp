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
#include <unordered_map>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	unordered_map<int,int>m;
	
	
	for(int i=0;i<n;i++){
		string str;
		int k,v;
		cin>>str;
		
		if(str=="add"){
			cin>>k>>v;
			m.erase(k);
			m.insert({k,v});
		}
		
		else if(str=="find"){
			cin>>k;
			if(m.find(k)==m.end()){
				cout<<"None"<<'\n';
			}
			else{
				cout<<m[k]<<'\n';
			}
		}
		
		else if(str=="remove"){
			cin>>k;
			m.erase(k);
		}
		
		
	}

}