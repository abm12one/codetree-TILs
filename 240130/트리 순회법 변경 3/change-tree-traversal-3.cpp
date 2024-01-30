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

vector<int>in;
vector<int>post;

void pre(int il,int ir,int pl,int pr){
	
	int p;
	int root=post[pr];
	if(il>ir){
		return;
	}
	for(int i=il;i<=ir;i++){
		if(in[i]==root){
			p=i;
			break;
		}
	}
	int s=p-il-1;
	cout<<root<<' ';
	pre(il,il+s,pl,pl+s);
	pre(p+1,ir,pl+s+1,pr-1);
	
	return;
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int n;
	cin>>n;
	in=vector<int>(n);
	post=vector<int>(n);
	
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	for(int i=0;i<n;i++){
		cin>>post[i];
	}
	
	pre(0,n-1,0,n-1);
	
}