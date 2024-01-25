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
#include <unordered_set>
#include<set>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,k;
	cin>>n>>k;
	vector<int>arr(n+1);
	vector<int>p(n+1);
	int fnode;
	
	for(int i=1;i<n+1;i++){
		cin>>arr[i];
		if(arr[i]==k){
			fnode=i;
		}
	}
	int pa=0;
	for(int i=2;i<n+1;i++){
		if(arr[i]>arr[i-1]+1){
			pa++;
		}
		p[i]=pa;	
	}
	int sum=0;
	for(int i=1;i<n+1;i++){
		if(p[p[fnode]]==0||p[p[i]]==0){
			continue;
		}
		if(p[fnode]!=p[i]&&p[p[fnode]]==p[p[i]]){
			sum++;
		}
		
	}
	cout<<sum<<'\n';
	
}