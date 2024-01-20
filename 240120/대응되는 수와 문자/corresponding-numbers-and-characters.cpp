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
	
	int n,m;
	cin>>n>>m;
	unordered_map<string,int>map;
	vector<string>words(n+1);
	for(int i=1;i<=n;i++){
		
		cin>>words[i];
		map[words[i]]=i;
	}
	
	for(int i=0;i<m;i++){
		string temp;
		cin>>temp;
		if(map.find(temp)==map.end()){
			
			cout<<words[stoi(temp)]<<'\n';
		}
		else{
			cout<<map[temp]<<'\n';
		}
		
	}
	
	
}