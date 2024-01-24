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

vector<int>pa;
vector<int>visit;
int n,ab,root;
int sum;
void dfs(int r){
	int flag=0;
	for(int i=0;i<n;i++){
		if(pa[i]==r&&visit[i]==0){
			flag=1;
			visit[i]=1;
			dfs(i);
		}
	}
	if(flag==0){
		sum++;
	}
	
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n;
	sum=0;
	pa=vector<int>(n);
	visit=vector<int>(n);
	for(int i=0;i<n;i++){
		cin>>pa[i];
		if(pa[i]==-1){
			root=i;
		}
	}
	
	cin>>ab;
	if(ab==root){
		cout<<0<<"\n";
	}
	else{
		visit[ab]=1;
		visit[root]=1;
	
		dfs(root);
	
		cout<<sum<<'\n';
	}
	
	
}