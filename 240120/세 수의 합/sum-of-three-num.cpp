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
	int ans=0;
	vector<int>arr(n);
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	for(int i=0;i<n-2;i++){
		unordered_map<int,int>map;
		
		int sum=m-arr[i];
		
		for(int j=i+1;j<n;j++){
			int there=sum-arr[j];
			if(map.count(there)>0){
				ans+=map[there];
			}
			
			map[arr[j]]++;
		}
		
		
	}
	cout<<ans<<'\n';
	
}