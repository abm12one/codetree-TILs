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

string str;
int as;
int ae;
int pel(int s,int e){
	
	int st=s;
	int ed=e;
	while(st>=0&&ed<str.size()&&str[st]==str[ed]){
		st--;
		ed++;
		
	}
	as=st+1;
	ae=ed-1;
	return ae-as+1;
	
}


int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>str;
	
	int ans=0;
	int start;
	int end;
	for(int i=0;i<str.size();i++){
		
		int temp=pel(i,i);
		
		if(ans<temp){
			ans=temp;
			start=as;
			end=ae;
		}
		
	}
	
	for(int i=0;i<str.size()-1;i++){
		
		int temp=pel(i,i+1);
		
		if(ans<temp){
			ans=temp;
			start=as;
			end=ae;
		}
		
	}
	//cout<<start<<' '<<end<<'\n';
	cout<<ans<<'\n';
	
	
}