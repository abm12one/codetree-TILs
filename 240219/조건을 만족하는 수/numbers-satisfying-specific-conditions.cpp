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
//#include <unordered_set>
//#include<set>
#include <iomanip>
using namespace std;

vector<vector<int>>pmap;
vector<vector<int>>mmap;
vector<int>pans;
vector<int>mans;
vector<int>pmapin;
vector<int>mmapin;
priority_queue<int>mmapq;
priority_queue<int,vector<int>,greater<int>>pmapq;
vector<int>rev;
void sol1(){
	
	while(!pmapq.empty()){
		
		int now=pmapq.top();
		pans.push_back(now);
		
		pmapq.pop();
		
		for(int i=0;i<pmap[now].size();i++){
			int there=pmap[now][i];
			
			pmapin[there]--;
			if(pmapin[there]==0){
				pmapq.push(there);
				
			}
			
		}
		
		
	}
	
	return ;
}


void sol2(){
	int cnt=1;
	while(!mmapq.empty()){
		
		int now=mmapq.top();
		mans.push_back(now);
		rev[now]=cnt++;
		mmapq.pop();
		
		
		for(int i=0;i<pmap[now].size();i++){
			int there=pmap[now][i];
			
			mmapin[there]--;
			if(mmapin[there]==0){
				mmapq.push(there);
			}
			
		}
		
		
	}
	
	return ;
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n;
	cin>>n;
	
	pmap=vector<vector<int>>(n+1);
	mmap=vector<vector<int>>(n+1);
	pmapin=vector<int>(n+1);
	mmapin=vector<int>(n+1);
	rev=vector<int>(n+1);
	for(int i=1;i<n;i++){
		char temp;
		cin>>temp;
		if(temp=='<'){
			pmap[i].push_back(i+1);
			pmapin[i+1]++;
			mmapin[i+1]++;
		}
		else{
			
			pmap[i+1].push_back(i);
			pmapin[i]++;
			mmapin[i]++;
		}
		
	}
	
	for(int i=1;i<n+1;i++){
		
		if(pmapin[i]==0){
			pmapq.push(i);
			mmapq.push(i);
		}
	}
	
	
	sol1();
	
	sol2();
	
	cout.fill('0');
    for(int i=0;i<n;i++){
		cout << setw(3) << pans[i];
	}    
    cout<<'\n';
	
	cout.fill('0');
    for(int i=1;i<=n;i++){
		cout << setw(3) << rev[i];
	}    
    cout<<'\n';
	

}