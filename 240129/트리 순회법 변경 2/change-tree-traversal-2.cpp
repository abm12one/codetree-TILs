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
vector<int>in;

void post(int pl,int pr,int il,int ir){
	
	//cout<<pl<<' '<<pr<<' '<<il<<' '<<ir<<'\n';
	
	if(pl==pr){
		cout<<pre[pl]<<' ';
		return;
	}
	
	int root=pre[pl];
	
	int dpoint; 
	
	for(int i=il;i<=ir;i++){
		
		if(in[i]==root){
			dpoint=i;
			break;
		}
		
	}
	
	int s=dpoint-il-1;//
	if(dpoint==il){
		
		post(pl+1,pr,il+1,ir);
		cout<<root<<' ';
		return;
	}
	else{
		post(pl+1,pl+s+1,il,dpoint-1);
	}
	
	if(dpoint!=ir){
		post(pl+s+2,pr,dpoint+1,ir);
	}
	
	
	cout<<root<<' ';
	
	return;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	int n;
	cin>>n;
	pre=vector<int>(n);
	in=vector<int>(n);
	
	for(int i=0;i<n;i++){
		cin>>pre[i];
	}
	for(int i=0;i<n;i++){
		cin>>in[i];
	}
	
	post(0,n-1,0,n-1);
	
}