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
int n;
vector<int>arr;
vector<int>tree;

void settree(int st,int ed,int n){
	
	if(st==ed){
		tree[n]=arr[st];
		return;
	}
	
	int mid=(st+ed)/2;
	tree[n]=arr[mid];
	
	settree(st,mid-1,2*n);
	settree(mid+1,ed,2*n+1);
	return;
	
	
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n;
	int s=pow(2,n);
	arr=vector<int>(s);
	tree=vector<int>(s);
	
	for(int i=1;i<s;i++){
		cin>>arr[i];
	}
	
	settree(1,s-1,1);
	
	int sum=0;
	int low=0;
	for(int i=1;i<s;i++){
		sum++;
		
		cout<<tree[i]<<' ';
		if(sum==pow(2,low)){
			cout<<'\n';
			low++;
			sum=0;
		}
	}
}