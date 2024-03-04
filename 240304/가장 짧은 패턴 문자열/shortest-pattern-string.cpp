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
//#include< map>
#include<unordered_set>
#include<set>
#define MAX_M 100000

using namespace std;

string text,pattern;

int n;

vector<int>f;

int main() {
	
	cin>>pattern;
	int pn=pattern.size();
	
	pattern='#'+pattern;
	
	f=vector<int>(pn+1);
	
	f[0]=-1;
	
	for(int i=1;i<=pn;i++){
		
		int j=f[i-1];
		
		while(j>=0&&pattern[i]!=pattern[j+1]){
			j=f[j];
		}
		
		f[i]=j+1;
		
	}
	
	cout<<pn-f[pn]<<'\n';
	
	
	
}