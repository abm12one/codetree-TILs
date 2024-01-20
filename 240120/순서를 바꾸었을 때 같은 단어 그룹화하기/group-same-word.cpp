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
	
	int n;
	cin>>n;
	unordered_map<string,int>map;
	
	for(int r=0;r<n;r++){
		vector<int>count(53,0);
		string str;
		cin>>str;
		for(int i=0;i<str.size();i++){
			count[str[i]-'A']++;
		}
		string temp="";
		for(int i=0;i<count.size();i++){
			
			for(int j=0;j<count[i];j++){
				
				temp+=char('A'+i);
			}
			
		}
		map[temp]++;
	}
	int mnum=0;
	for(unordered_map<string,int>::iterator it=map.begin();it!=map.end();it++){
		mnum=max(mnum,it->second);
		
	}
	cout<<mnum<<'\n';
	
}