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
vector<int>tree;
vector<vector<int>>list;
int dfs(int n){
	
	int &ret=tree[n];
	for(int i=0;i<list[n].size();i++){
		int there=list[n][i];
		
		
		ret+=dfs(there);
	}
	if(ret<0){
		return 0;
	}
	return ret;
	
	
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int n;
	cin>>n;
	tree=vector<int>(n+1);
	list=vector<vector<int>>(n+1);
	for(int i=2;i<=n;i++){
		int t,a,p;
		cin>>t>>a>>p;
		list[p].push_back(i);
		if(t==1){
			tree[i]=a;
		}
		else{
			tree[i]=-a;
		}	
	}
	
	cout<<dfs(1);
	
}