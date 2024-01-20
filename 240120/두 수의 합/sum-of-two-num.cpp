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
	
	for(int i=1;i<=n;i++){
		int temp;
		cin>>temp;
		map[temp]++;
	}
	
	
	for(int i=1;i<=m/2;i++){
		if(map.find(i)==map.end()){
			continue;
		}
		else{
			int there=m-i;
			if(there==i){
				ans+=map[i]*(map[i]-1)/2;
			}
			else if(map.find(there)==map.end()){
				continue;
			}
			else{
				ans+=map[i]*map[there];
			}
			
			
			
		}
		
		
	}
	cout<<ans<<'\n';
	
}