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
	unordered_map<int,int>mp;
	
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		if(mp.find(num)==mp.end()){
			mp[num]=1;
		}
		else{
			mp[num]++;
		}
		
	}
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		if(mp.find(temp)==mp.end()){
			cout<<0<<'\n';
		}
		else{
			cout<<mp[temp]<<'\n';
		}
	}
	

}