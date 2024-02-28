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
//#include< unordered_map>
//#include< map>
//#include < unordered_set>
#include<set>

using namespace std;

string str,arr;
vector<int>a;

char f;
set<int>s;

int check(int n){
	
	if(str[n]=='#'){
		auto nc=s.upper_bound(n);
		if(nc==s.end())return a[n];
		int nextc=*nc;
		//cout<<"큰거"<<nextc<<'\n';
		return min(a[n],nextc-n-1);
	}
	else{
		auto nc=s.upper_bound(n);
		if(nc==s.end())return a[n];
		int nextc=*nc;
		//cout<<"작은거"<<nextc<<'\n';
		return min(a[n],nextc-n-1);
	}
	
	
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int any;
	cin>>any;
	
	cin>>f;
	
	cin>>arr;
	
	for(int i=0;i<arr.size();i++){
		str+='#';
		str+=arr[i];
		if(arr[i]==f){
			s.insert(2*i+1);
		}
	}
	str+='#';
	
	int r=-1;
	int p=-1;
	int n=str.size();
	
	a=vector<int>(n);
	
	for(int i=0;i<n;i++){
		
		if(r>=i){
			int ii=2*p-i;
			a[i]=min(a[ii],r-i);
		}
		
		while(i-a[i]-1>=0&&i+a[i]+1<n&&str[i-a[i]-1]==str[i+a[i]+1]){
			a[i]++;
		}
		
		
		if(r<i+a[i]){
			p=i;
			r=i+a[i];
		}
			
	}
	int ans=0;
	/*
	for(auto it=s.begin();it!=s.end();it++){
		cout<<*it<<' ';
	}
	cout<<'\n';
	*/
	for(int i=0;i<n;i++){
		
		if(str[i]==f)continue;
		ans=max(ans,check(i));
		
	}
	
	cout<<ans<<'\n';
	
	
}