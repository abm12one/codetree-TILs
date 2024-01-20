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
	int ans=0;
	unordered_map<int,int>map1;
	unordered_map<int,int>map2;
	vector<vector<int>>arr(4,vector<int>(n,0));
	
	for(int i=0;i<4;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
		}
	}
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			
			map1[arr[0][i]+arr[1][j]]++;
			map2[arr[2][i]+arr[3][j]]++;
			
		}
	}
	
	for(unordered_map<int,int>::iterator it=map1.begin();it!=map1.end();it++){
		
		int now=it->first;
		int rep=it->second;
		
		if(map2.count(-now)>0){
			ans+=rep*map2[-now];
		}
		
	}
	cout<<ans<<"\n";
	
}