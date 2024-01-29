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

vector<int>le;
vector<int>ri;
int n;
int ans;
void put(int r,int k){
	
	if(le[r]==-1&&ri[r]==-1){
		ans=r;
	}
	else if(le[r]==-1){
		put(ri[r],k);
	}
	else if(ri[r]==-1){
		put(ri[r],k);
	}
	else{
		if(k%2==0){
			put(le[r],k/2);
		}
		else{
			put(le[r],k/2+1);	
		}
	}
	return;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n;
	
	le=vector<int>(n+1);
	ri=vector<int>(n+1);
	for(int i=1;i<n+1;i++){
		cin>>le[i]>>ri[i];
	}
	int k;
	cin>>k;
	put(1,k);
	cout<<ans<<'\n';
}