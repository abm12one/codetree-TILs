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
int n,m;
vector<string>a;
vector<string>b;
int sum=0;

void isok(int x,int y,int z){
	
	unordered_set<string>s;
	
	for(int i=0;i<n;i++){
		string temp="";
		temp+=a[i][x]+a[i][y]+a[i][z];
		s.insert(temp);
	}
	
	for(int i=0;i<n;i++){
		string temp="";
		temp+=b[i][x]+b[i][y]+b[i][z];
		if(s.find(temp)!=s.end()){
			return;
		}
	}
	
	sum++;
	return;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n>>m;
	a=vector<string>(n);
	b=vector<string>(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	sum=0;
	for(int i=0;i<m-2;i++){
		for(int j=i+1;j<m-1;j++){
			for(int k=j+1;k<m;k++){
				
				isok(i,j,k);
				
				
			}
		}
	}
	cout<<sum<<'\n';
	
}