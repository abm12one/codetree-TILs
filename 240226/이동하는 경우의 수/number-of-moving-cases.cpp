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
//#include< unordered_map>
//#include< map>
//#include < unordered_set>
//#include< set>

using namespace std;

queue<int>q;
vector<int>in;
vector<int>in2;
vector<int>cache;
vector<int>visit;
vector<vector<int>> before;
typedef struct{
	int dest;
	int dis;

}node;

vector<vector<node>>map;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	in=vector<int>(n+1);
	visit=vector<int>(n+1);
	map=vector<vector<node>>(n+1);
	cache=vector<int>(n+1,-1);
	before=vector<vector<int>>(n+1);
	for(int i=0;i<m;i++){
		
		int a,b,d;
		cin>>a>>b>>d;
		map[a].push_back(node{b,d});
		in[b]++;

	}
	
	for(int i=1;i<n+1;i++){
		if(in[i]==0){
			q.push(i);
			
		}
	}

	int cnt=0;

	while(!q.empty()){

		int now=q.front();
		q.pop();
		for(int i=0;i<map[now].size();i++){
			int there=map[now][i].dest;
			int v=map[now][i].dis;
			if(cache[now]==-1)continue;

			if(cache[there]<cache[now]+v){
				cache[there]=cache[now]+v;
				before[there].clear();
                before[there].push_back(now);
			}
			else if(cache[there]==cache[now]+v){
				before[there].push_back(now);
			}
			in[there]--;
			if(in[there]==0){
				q.push(there);
			}
		}
	}

	cout<<cache[n]<<' ';

	q.push(n);
    visit[n] = 1;

    while(!q.empty()) {
        int x = q.front();
        q.pop();

        for(int i = 0; i < before[x].size(); i++) {
            int y = before[x][i];

            cnt++;

            if(visit[y]) 
                continue;

            visit[y] = 1;
            q.push(y);
        }
    }
	cout<<cnt<<'\n';

	

	

}