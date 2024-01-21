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

using namespace std;

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	unordered_set<int>s;
	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		int temp;
		cin>>temp;
		if(str=="find"){
			if(s.find(temp)!=s.end()){
				cout<<"true"<<'\n';
				
			}
			else{
				cout<<"false"<<'\n';
			}
		}
		else if(str=="add"){
			s.insert(temp);
		}
		else if(str=="remove"){
			s.erase(temp);
		}
		
	}

}