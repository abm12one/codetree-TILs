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

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin>>n;
	set<int>s;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		
		if(str=="add"){
			int temp;
			cin>>temp;
			s.insert(temp);
		}
		else if(str=="largest"){
			if(s.size()==0){
				cout<<"None"<<'\n';
			}
			else{
				cout<<*s.rbegin()<<'\n';
			}
		}
		else if(str=="smallest"){
			if(s.size()==0){
				cout<<"None"<<'\n';
			}
			else{
				cout<<*s.begin()<<'\n';
			}
		}
		else if(str=="find"){
			int temp;
			cin>>temp;
			if(s.find(temp)!=s.end()){
				cout<<"true"<<'\n';
			}
			else{
				cout<<"false"<<'\n';
			}
		}
		else if(str=="lower_bound"){
			int temp;
			cin>>temp;
			if(s.lower_bound(temp)==s.end()){
				cout<<"None"<<'\n';
			}
			else{
				cout<<*s.lower_bound(temp)<<'\n';
			}
		}
		else if(str=="upper_bound"){
			int temp;
			cin>>temp;
			if(s.upper_bound(temp)==s.end()){
				cout<<"None"<<'\n';
			}
			else{
				cout<<*s.upper_bound(temp)<<'\n';
			}
		}
		else if(str=="remove"){
			int temp;
			cin>>temp;
			s.erase(temp);
			
		}
	}
	
	
}