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
		
		string str;
		cin>>str;
		sort(str.begin(),str.end());
		map[str]++;
		mnum=max(mnum,map[str]);
	}
	
	
	cout<<mnum<<'\n';
	
}