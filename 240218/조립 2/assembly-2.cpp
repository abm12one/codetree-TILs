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
vector<vector<int>>map;
vector<int>visit;
queue<int>q;
vector<int>ans;
vector<int>in;
void solve(){
	
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<map[now].size();i++){
			int there=map[now][i];
			in[there]--;
			if(in[there]==0&&visit[there]==0){
				visit[there]=1;
				q.push(there);
				ans.push_back(there);
			}
			
		}
		
		
	}
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	map=vector<vector<int>>(n+1);
	visit=vector<int>(n+1);
	in=vector<int>(n+1);
	for(int i=0;i<m;i++){
		int now,num;
		cin>>now>>num;
		for(int j=0;j<num;j++){
			int temp;
			cin>>temp;
			map[temp].push_back(now);
			in[now]++;
		}
		
		
	}
	int get;
	cin>>get;
	for(int i=0;i<get;i++){
		int temp;
		cin>>temp;
		visit[temp]=1;
		ans.push_back(temp);
		q.push(temp);
	}
	solve();
	
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<'\n';
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<' ';
	}