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
	
	unordered_map<int,int>map;
	int ans=0;
	int n,m;
	cin>>n>>m;
	vector<int>arr(n+1);
	vector<int>visit(m+1,0);
	for(int i=1;i<=n;i++){
		
		cin>>arr[i];
		map[arr[i]]++;
	}
	
	sort(arr.begin(),arr.end());
	
	for(int i=1;i<=n+1;i++){

		if(arr[i]>m/2)break;
		
		if(visit[arr[i]]==1)continue;
		
		visit[arr[i]]=1;
		
		int there=m-arr[i];
		
		if(map.find(there)==map.end()){
			continue;
		}
		
		int v=map[arr[i]];
		
		if(there==arr[i]){
			ans+=v*(v-1)/2;
		}
		
		else{
			ans+=v*map[there];
		}
		
	}
	
	cout<<ans<<'\n';
	
}