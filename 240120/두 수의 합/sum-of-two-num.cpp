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
vector<int>arr;
int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans=0;
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}
	sort(arr.begin(),arr.end());
	int st=0;
	int ed=n-1;
	while(st<ed){
		if(arr[st]+arr[ed]<m){
			st++;
		}
		else if(arr[st]+arr[ed]==m){
			st++;
			ans++;
		}
		else if(arr[st]+arr[ed]>m){
			ed--;
		}
		
	}
	cout<<ans<<'\n';
	
}