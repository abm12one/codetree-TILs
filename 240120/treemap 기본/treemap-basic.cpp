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

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	map<int ,int>m;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		if(str=="add"){
			int k,v;
			cin>>k>>v;
			m[k]=v;
		}
		else if(str=="find"){
			int k;
			cin>>k;
			if(m.find(k)==m.end()){
				cout<<"None"<<'\n';
			}
			else{
				cout<<m[k]<<'\n';
			}
		}
		else if(str=="remove"){
			int k;
			cin>>k;
			m.erase(k);
		}
		else if(str=="print_list"){
			int flag=0;
			for(map<int,int>::iterator it=m.begin();it!=m.end();it++){
				flag=1;
				cout<<it->second<<' ';
			}
			if(flag==1){
				cout<<'\n';
			}
			if(flag==0){
				cout<<"None"<<'\n';
			}
		}
		
	}
	
}