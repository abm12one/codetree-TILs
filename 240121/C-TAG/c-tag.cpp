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

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	vector<string>a(n);
	vector<string>b(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}
	int sum=0;
	for(int i=0;i<m-2;i++){
		for(int j=i+1;j<m-1;j++){
			for(int k=j+1;k<m;k++){
				
				unordered_set<string>all;
				unordered_set<string>arr1;
				unordered_set<string>arr2;
				
				for(int r=0;r<n;r++){
					string temp1="";
					temp1+=a[r][i];
					temp1+=a[r][j];
					temp1+=a[r][k];
					string temp2="";
					temp2+=b[r][i];
					temp2+=b[r][j];
					temp2+=b[r][k];
					all.insert(temp1);
					all.insert(temp2);
					arr1.insert(temp1);
					arr2.insert(temp2);
				}
				if(all.size()==arr1.size()+arr2.size()){
					sum++;
				}
				
				
			}
		}
	}
	cout<<sum<<'\n';
	
}