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

vector<vector<int>>arr;
int n,m;
void setting(){
	
	for(int k=1;k<n+1;k++){
		for(int i=1;i<n+1;i++){
			for(int j=1;j<n+1;j++){
				arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
			}
			
		}
	}
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n>>m;
	arr=vector<vector<int>>(n+1,vector<int>(n+1,987654321));
	
	for(int i=0;i<n-1;i++){
		int a,b,v;
		cin>>a>>b>>v;
		arr[a][b]=v;
		arr[b][a]=v;
		arr[i+1][i+1]=0;
	}
	
	setting();
	
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		cout<<arr[a][b]<<'\n';
	}
	
	
}