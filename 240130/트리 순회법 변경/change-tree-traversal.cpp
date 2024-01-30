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

vector<int>pre;

void post(int s,int e){
	if(s>e){
		return;
	}
	
	if(s==e){
		cout<<pre[s]<<"\n";
		return;
	}
	
	int root=pre[s];
	int p=s;
	
	for(int i=s+1;i<=e;i++){
		if(pre[i]<root){
			p=i;
		}
		else{
			break;
		}
	}
	
	post(s+1,p);
	post(p+1,e);
	cout<<root<<'\n';
	
	return;
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int n;
	cin>>n;
	pre=vector<int>(n);
	
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	post(0,n-1);
	
}