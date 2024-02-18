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
int n;
int solve(){
	int num=0;
	while(!q.empty()){
		int now=q.front();
		num++;
		q.pop();
		for(int i=0;i<map[now].size();i++){
			int there=map[now][i];
			in[there]--;
			if(in[there]==0){
				q.push(there);
				
			}
			
		}
		
		
	}
	return num;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m1,m2;
	cin>>n>>m1>>m2;
	map=vector<vector<int>>(n+1);
	in=vector<int>(n+1);
	for(int i=0;i<m1;i++){
		int a,b;
		cin>>a>>b;
		map[a].push_back(b);
		in[b]++;
	}
	
	for(int i=1;i<n+1;i++){
		if(in[i]==0){
			q.push(i);
		}
	}
	

	if(solve()==n){
		cout<<"Yes"<<'\n';
	}
	else{
		cout<<"No"<<'\n';
	}
	
	for(int i=0;i<m2;i++){
		int a,b;
		cin>>a>>b;
	
	}
	
	
}