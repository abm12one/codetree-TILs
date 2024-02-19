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
//#include <unordered_set>
//#include<set>
#include <iomanip>
using namespace std;
vector<vector<int>>map;
priority_queue<int,vector<int>,greater<int>>pq;
vector<int>arr;
vector<int>in;
int num=0;
void sol(){
	int cnt=1;
	
	while(!pq.empty()){
		
		int now=pq.top();
	
		arr[now]=cnt++;
		num++;
		pq.pop();
		for(int i=0;i<map[now].size();i++){
			int there=map[now][i];
			in[there]--;
			if(in[there]==0){
				pq.push(there);
			}
		}
		
	}
	
	return ;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	in=vector<int>(n+1);
	arr=vector<int>(n+1);
	map=vector<vector<int>>(n+1);
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		map[a].push_back(b);
		in[b]++;
	}
	
	/*
	for(int i=1;i<n+1;i++){
		sort(map[i].begin(),map[i].end());
	}
	*/
	
	for(int i=1;i<n+1;i++){
		if(in[i]==0){
			pq.push(i);
		}
	}
	
	sol();
	if(num!=n){
		cout<<-1<<'\n';
	}
	else{
		for(int i=1;i<n+1;i++){
			cout<<arr[i]<<' ';
		}		
	}
	

}