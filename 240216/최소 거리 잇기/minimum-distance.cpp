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

vector<int>p;
vector<int>v;

typedef struct{
	double value;
	int st;
	int ed;
	
}node;

typedef struct{
	int y;
	int x;
	
}edge;


bool compare(node n1,node n2){
	return n1.value<n2.value;
}

vector<node>arr;

vector<edge>earr;

double fdis(int ay, int ax,int by,int bx){
	
	double dy=(double)abs(ay-by);
	double dx=(double)abs(ax-bx);
	
	return (double)sqrt(pow(dy,2)+pow(dx,2));
	
}
int find(int a){
	if(p[a]==a){
		return p[a];
	}
	
	return p[a]=find(p[a]);
}

int uset(int a,int b){
	
	int fa=find(a);
	int fb=find(b);
	if(fa==fb){
		return 0;
	}
	
	p[fa]=fb;
	return 1;
	
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m;
	cin>>n>>m;
	
	p=vector<int>(n+1);
	for(int i=0;i<n+1;i++){
		p[i]=i;
	}
	
	earr.push_back(edge{0,0});
	for(int i=0;i<n;i++){
		
		int ay,ax;
		cin>>ay>>ax;
		earr.push_back(edge{ay,ax});
		
	}
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		uset(a,b);
	}
	
	for(int i=1;i<earr.size()-1;i++){
		for(int j=i+1;j<earr.size();j++){
			arr.push_back(node{fdis(earr[i].y,earr[i].x,earr[j].y,earr[j].x),i,j});
		}
	}
	sort(arr.begin(),arr.end(),compare);

	double sum=0;
	for(int i=0;i<arr.size();i++){
		if(uset(arr[i].st,arr[i].ed)==0)continue;
		sum+=arr[i].value;
		
	}
	cout<<fixed;
	cout.precision(2);
	cout<<sum<<'\n';
	
}