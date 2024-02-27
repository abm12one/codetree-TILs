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
//#include< set>

using namespace std;

string str,arr;
vector<int>a;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>arr;
	for(int i=0;i<arr.size();i++){
		str+='#';
		str+=arr[i];
	}
	str+='#';
	
	int r=-1;
	int p=-1;
	int n=str.size();
	
	a=vector<int>(n);
	
	long cnt=0;
	for(int i=0;i<n;i++){
		
		if(r>=i){
			int ii=2*p-i;
			a[i]=min(a[ii],r-i);
		}
		
		while(i-a[i]-1>=0&&i+a[i]+1<n&&str[i-a[i]-1]==str[i+a[i]+1]){
			a[i]++;
		}
		
		cnt+=(a[i]+1)/2;
		
		if(r<i+a[i]){
			p=i;
			r=i+a[i];
		}
			
	}
	cout<<cnt<<"\n";
	
}