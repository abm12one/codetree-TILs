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

using namespace std;

unordered_set<int>ga;
unordered_set<int>gb;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		ga.insert(temp);
	}
	for(int i=0;i<m;i++){
		int temp;
		cin>>temp;
		if(ga.find(temp)==ga.end()){
			gb.insert(temp);
		}
		else{
			ga.erase(temp);
		}
	}
	
	cout<<ga.size()+gb.size()<<'\n';
}