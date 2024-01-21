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

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	unordered_set<int>s[100001];
	
	
	int n,m;
	cin>>n>>m;
	
	vector<int>arr(n+1,0);
	vector<int>ans(n+1,0);
	vector<int>a(m+1,0);
	vector<int>b(m+1,0);
	
	for(int i=1;i<=n;i++){
		arr[i]=i;
		s[i].insert(i);
		ans[i]=1;
	}
	
	for(int i=0;i<m;i++){
		cin>>a[i]>>b[i];
	}
	for(int r=0;r<3;r++){
		for(int i=0;i<m;i++){
			swap(arr[a[i]],arr[b[i]]);
			if(s[arr[a[i]]].find(a[i])==s[arr[a[i]]].end()){
				s[arr[a[i]]].insert(a[i]);
				ans[arr[a[i]]]++;
			}
			if(s[arr[b[i]]].find(b[i])==s[arr[b[i]]].end()){
				s[arr[b[i]]].insert(b[i]);
				ans[arr[b[i]]]++;
			}
			
			
		}
	}
	for(int i=1;i<=n;i++){
		cout<<ans[i]<<'\n';
	}
	
	
	
}