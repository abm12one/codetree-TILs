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
queue<int>q;
vector<int>visit;
vector<int>in;
vector<vector<int>>map;
int n,m;
vector<int>ans;
void solve(){
	
	while(!q.empty()){
		int now=q.front();
		ans.push_back(now);
		q.pop();
		for(int i=0;i<map[now].size();i++){
			int there=map[now][i];
			in[there]--;
			if(in[there]==0){
				q.push(there);
			}
			
		}
		
	}
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>m;
	visit=vector<int>(n+1);
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
			q.push(i);
		}
	}
	
	solve();
	reverse(ans.begin(),ans.end());
	if(ans.size()==n){
		cout<<"Consistent"<<'\n';
	}
	else{
		cout<<"Inconsistent"<<'\n';
	}
}