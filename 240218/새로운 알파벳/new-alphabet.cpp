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
vector<vector<int>>m;
vector<int>visit;
queue<int>q;
vector<int>ans;
vector<int>in;

int n;
int var;
map<char,int>char_to_int;
map<int,char>int_to_char;

int solve(){
	
	int num=0;
	
	while(!q.empty()){
		
		if(q.size()>1){
			var=1;
		}
		
		int now=q.front();
		
		num++;
		q.pop();
		
		
		for(int i=0;i<m[now].size();i++){
			int there=m[now][i];
			
			in[there]--;
			if(in[there]==0){
				q.push(there);
				ans.push_back(there);
			}
			
		}
		
		
	}
	
	return num;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n;
	var=0;
	vector<string>words(n);

	for(int i=0;i<n;i++){
		cin>>words[i];
	}
	
	int id=0;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<words[i].size();j++){
			char temp=words[i][j];
			if(char_to_int.find(temp)==char_to_int.end()){
				char_to_int[temp]=++id;
				int_to_char[id]=temp;
			}
			
		}
	}	
	
	m=vector<vector<int>>(id+1);
	in=vector<int>(id+1);
	
	for(int i=0;i<n-1;i++){
		
		int as=words[i].size();
		int bs=words[i+1].size();
		int ms=min(as,bs);
		
		for(int j=0;j<ms;j++){
			
			if(words[i][j]!=words[i+1][j]){
				char now=words[i][j];
				char there=words[i+1][j];
				m[char_to_int[now]].push_back(char_to_int[there]);
				in[char_to_int[there]]++;
				break;
			}

		}
		
		
	}

	for(int i=1;i<id+1;i++){
		if(in[i]==0){
			q.push(i);
			ans.push_back(i);
			
			
		}
	}
	
	if(solve()!=id){
		cout<<"-1"<<'\n';
	}
	
	else if(var==1){
		cout<<"inf"<<'\n';
	}
	else{
		for(int i=0;i<ans.size();i++){
			cout<<int_to_char[ans[i]];
		}
	}
	
}