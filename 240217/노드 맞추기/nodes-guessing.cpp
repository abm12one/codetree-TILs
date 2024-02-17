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

map<string,int>stoi;
vector<vector<int>>g;
vector<vector<int>>child;
vector<int>in;
queue<int>q;
vector<string>str;

void solve(){
	
	while(!q.empty()){
		int now=q.front();
		q.pop();
		for(int i=0;i<g[now].size();i++){
			int there=g[now][i];
			in[there]--;
			if(in[there]==0){
				
				q.push(there);
				child[now].push_back(there);
			}
			
		}
		
		
	}
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	map<string,int>stoi;
	int n;
	cin>>n;
	g=vector<vector<int>>(n+1);
	child=vector<vector<int>>(n+1);
	in=vector<int>(n+1);
	str=vector<string>(n+1);
	for(int i=1;i<=n;i++){
		string temp;
		cin>>temp;
		stoi[temp]=i;
		str[i]=temp;
	}
	
	int m;
	cin>>m;
	for(int i=0;i<m;i++){
		string a,b;
		cin>>a>>b;
		int na=stoi[a];
		int nb=stoi[b];
		
		g[nb].push_back(na);
		in[na]++;
		
	}
	vector<int>root;
	
	for(int i=1;i<n+1;i++){
		if(in[i]==0){
			q.push(i);
			root.push_back(i);
		}
	}
	
	cout<< root.size()<<'\n';
	sort(root.begin(),root.end());
	
	for(int i=0;i<root.size();i++){
		
		
		cout<<str[root[i]]<<' ';
	}
	cout<<'\n';
	
	solve();
	
	
	for(int i=1;i<n+1;i++){
		
		cout<<str[i]<<' ';
		sort(child[i].begin(),child[i].end());
		cout<<child[i].size()<<' ';
		for(int j=0;j<child[i].size();j++){
			
			cout<<str[child[i][j]]<<' ';
		}
		cout<<'\n';
	}
	
	
}