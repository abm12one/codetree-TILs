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
#include <unordered_map>

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int mnum=100001;
	unordered_map<char,int>map;
	string str;
	vector<int>visit(26);
	cin>>str;
	for(int i=0;i<str.size();i++){
		map[str[i]]++;
		visit[str[i]-'a']=i;
	}
	
	for(unordered_map<char,int>::iterator it=map.begin();it!=map.end();it++){
		if(it->second==1){
			
			mnum=min(mnum,visit[(it->first)-'a']);
		}
		//cout<<it->first<<' '<<it->second<<'\n';
	}
	if(mnum==100001){
		cout<<"None";
	}
	else{
		cout<<str[mnum];
	}
}