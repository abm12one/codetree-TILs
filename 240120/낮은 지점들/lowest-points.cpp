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
	unordered_map<int,long>map;
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int x;
		long y;
		cin>>x>>y;
		if(map.count(x)==0){
			map[x]=y;
		}
		else{
			if(map[x]>y){
				map[x]=y;
			}
		}
	}
	long sum=0;
	for(unordered_map<int,long>::iterator it=map.begin();it!=map.end();it++){
		sum+=it->second;
	}
	cout<<sum<<'\n';
}