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
	
	for(int r=0;r<n;r++){
		int t;
		cin>>t;
		s.clear();
		for(int i=0;i<t;i++){
			string str;
			cin>>str;
			int v;
			cin>>v;
			
			if(str=="I"){
				s.insert(v);	
			}
			else if(str=="D"){
				if(v==-1&&s.size()>0){
					s.erase(*s.begin());
				}
				else if(v==1&&s.size()>0){
					s.erase(*s.rbegin());
				}
			}
			
		}
		if(s.size()==0){
			cout<<"EMPTY"<<'\n';
		}
		else{
			cout<<*s.begin()<<' '<<*s.rbegin()<<'\n';
		}
	}

	
}