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

vector<int>t;
vector<int>in;
vector<int>dis;
vector<vector<int>>pre;
vector<vector<int>>map;

queue<int>q;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	t=vector<int>(n+1);
	in=vector<int>(n+1);
	dis=vector<int>(n+1);
	pre=vector<vector<int>>(n+1);
	map=vector<vector<int>>(n+1);
	for(int i=1;i<n+1;i++){
		cin>>t[i];
		while(1){
			
			int temp;
			cin>>temp;
			if(temp==-1)break;
			pre[i].push_back(temp);
			map[temp].push_back(i);
			in[i]++;
			
		}
		
		
	}
	
	for(int i=1;i<n+1;i++){
		if(in[i]==0){
			q.push(i);
			dis[i]=t[i];
		}
	}
	
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<map[now].size();i++){
			int there=map[now][i];
			in[there]--;
			dis[there]=max(dis[there],dis[now]+t[there]);
			if(in[there]==0){
				q.push(there);
			}
			
			
		}
		
	}
	for(int i=1;i<n+1;i++){
		cout<<dis[i]<<'\n';
	}
	
}