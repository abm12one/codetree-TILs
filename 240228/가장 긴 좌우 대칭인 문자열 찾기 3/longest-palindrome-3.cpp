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
vector<int>warr;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int any;
	cin>>any;
	
	char find;
	cin>>find;
	
	cin>>arr;
	for(int i=0;i<arr.size();i++){
		str+='#';
		str+=arr[i];
		if(arr[i]==find){
			warr.push_back(2*i+1);
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
	int st;
	int ed;
	for(int i=0;i<n;i++){
		
		int s=i-a[i];
		int e=i+a[i];
		int len=(e-s)/2;
		int flag=0;
		for(int j=0;j<warr.size();j++){
			if(s<=warr[j]&&warr[j]<=e){
				flag=1;
				break;
			}
		}
		if(flag==1)continue;
		
		if(ans<len){
			ans=len;
			st=s;
			ed=e;
		}
		
	}
	//cout<<st<<' '<<ed<<'\n';
	//cout<<str[st]<<' '<<str[ed]<<'\n';
	cout<<ans<<'\n';
	
	
}