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

vector<int>visit;

int isok(int now){
	int temp=now;
	while(temp>0){
		
		if(visit[temp]==0){
			temp=temp/2;
		}
		else{
			return temp;
		}
		
	}
	visit[now]=1;
	//cout<<now<<"is visited"<<"\n";
	return 0;
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,num;
	
	cin>>n>>num;
	visit=vector<int>(n+1,0);
	
	for(int i=0;i<num;i++){
		int now;
		cin>>now;
		cout<<isok(now)<<'\n';
	}
	
	
	
}