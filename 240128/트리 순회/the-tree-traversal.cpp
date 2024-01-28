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

vector<int>l;
vector<int>r;

void pre(int n){
	if(n==0){
		return;
	}
	char temp='A'+n-1;
	cout<<temp;;
	pre(l[n]);
	pre(r[n]);
	
}
void in(int n){
	if(n==0){
		return;
	}
	char temp='A'+n-1;
	
	in(l[n]);
	cout<<temp;
	in(r[n]);
	
}
void post(int n){
	if(n==0){
		return;
	}
	char temp='A'+n-1;
	
	post(l[n]);
	post(r[n]);
	cout<<temp;
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	l=vector<int>(n+1);
	r=vector<int>(n+1);
	
	for(int i=0;i<n;i++){
		
		char a,b,c;
		cin>>a>>b>>c;
		int root,left,right;
		root=a-'A'+1;
		if(b=='.'){
			left=0;
			
		}
		else{
			left=b-'A'+1;
		}
		
		if(c=='.'){
			right=0;
			
		}
		else{
			right=c-'A'+1;
		}
		
		
		l[root]=left;
		r[root]=right;
		
	}
	pre(1);
	cout<<'\n';
	in(1);
	cout<<'\n';
	post(1);
	
}