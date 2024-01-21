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

unordered_set<int>group[250001];
vector<int>where[100001];
int visit[250001];
queue<int>que;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,g;
	cin>>n>>g;
	
	
	
	for(int i=1;i<=g;i++){
		int r;
		cin>>r;
		for(int j=0;j<r;j++){
			int temp;
			cin>>temp;
			group[i].insert(temp);
			where[temp].push_back(i);
			
		}
	}
	int ans=0;
	visit[1]=1;
	que.push(1);
	
	while(!que.empty()){
		int now=que.front();
		ans++;
		que.pop();
		
		for(int i=0;i<where[now].size();i++){
			int there=where[now][i];
			
			group[there].erase(now);
			
			if(group[there].size()==1){
				int next=*(group[there].begin());
				if(!visit[next]){
					visit[next]=1;
					que.push(next);	
				}
				
				
				
			}
		}
		
		
	}
	cout<<ans<<'\n';
	return 0;
}