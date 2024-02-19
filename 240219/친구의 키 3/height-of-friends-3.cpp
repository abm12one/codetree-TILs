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
//#include<unordered_map>
//#include<map>
#include <unordered_set>
#include<set>

using namespace std;
priority_queue<int,vector<int>,greater<int>>pq;
vector<int>in;
vector<vector<int>>map;

int n,m;
vector<int>ans;
int num;
void solve(){
	num=0;
	while(!pq.empty()){
		int now=pq.top();
		num++;
		ans.push_back(now);
		pq.pop();
		for(int i=0;i<map[now].size();i++){
			int there=map[now][i];
			in[there]--;
			if(in[there]==0){
				pq.push(there);
			}
			
		}
		
	}
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	in=vector<int>(n+1);
	map=vector<vector<int>>(n+1);
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		in[b]++;
		map[a].push_back(b);
	}
	
	
	for(int i=1;i<n+1;i++){
		if(in[i]==0){
			pq.push(i);
		}
	}
	
	solve();
	if(num!=n){
		cout<<-1<<'\n';
	}
	else{
		for(int i=0;i<ans.size();i++){
			cout<<ans[i]<<' ';
		}
	}
	
}