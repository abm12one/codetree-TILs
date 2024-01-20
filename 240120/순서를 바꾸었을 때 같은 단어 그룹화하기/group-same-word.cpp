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
	int mnum=0;
	for(int r=0;r<n;r++){
		vector<int>count(52,0);
		string str;
		cin>>str;
		for(int i=0;i<str.size();i++){
			count[str[i]-'A']++;
		}
		string temp="";
		for(int i=0;i<count.size();i++){
			if(count[i]==0)continue;
			else{
				temp+=char('0'+count[i]);
				temp+=char('A'+i);
			}
			
			
			
		}
		mnum=max(mnum,++map[temp]);
	}
	
	
	cout<<mnum<<'\n';
	
}