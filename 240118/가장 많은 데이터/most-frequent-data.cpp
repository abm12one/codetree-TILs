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
	unordered_map<string,int>m;
	int msum=0;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		m[str]++;
		msum=max(msum,m[str]);
	}
	
	cout<<msum<<'\n';
}