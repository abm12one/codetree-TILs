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
//#include<unordered_map>
//#include<map>
#include <unordered_set>
#include<set>

using namespace std;
int num;
int n;
vector<int>p;
vector<vector<int>>dis;
vector<vector<int>>visit;
vector<vector<int>>edgenum;
vector<vector<int>>map;
typedef struct{
	int y;
	int x;
	
}node;

typedef struct{
	int value;
	int st;
	int ed;
	
}edge;

bool compare(edge e1,edge e2){
	return e1.value<e2.value;
}

vector<edge>arr;

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
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int isin(int y,int x){
	
	if(y>=0&&y<n&&x>=0&&x<n){
		return 1;
	}
	return 0;
	
}

void bfs(int y,int x){
	
	queue<node>q;
	q.push(node{y,x});
	int nownum=edgenum[y][x];
	visit=vector<vector<int>>(n,vector<int>(n,0));
	dis=vector<vector<int>>(n,vector<int>(n,0));
	visit[y][x]=1;
	dis[y][x]=0;
	
	
	while(!q.empty()){
		
		int hy=q.front().y;
		int hx=q.front().x;
		q.pop();
		
		for(int i=0;i<4;i++){
			
			int ny=hy+dy[i];
			int nx=hx+dx[i];
			
			if(isin(ny,nx)==0||visit[ny][nx]!=0){
				continue;
			}
			
			
			visit[ny][nx]=1;
			dis[ny][nx]=dis[hy][hx]+1;
			if(map[ny][nx]==-1)continue;
			
			if(map[ny][nx]==1||map[ny][nx]==2){
				arr.push_back(edge{dis[ny][nx],nownum,edgenum[ny][nx]});
			}
			q.push(node{ny,nx});
			
			
		}
		
		
		
	}
	
	
}
int solve(){
	int sum=0;
	int en=0;
	sort(arr.begin(),arr.end(),compare);
	for(int i=0;i<arr.size();i++){
		if(uset(arr[i].st,arr[i].ed)==0)continue;
		sum+=arr[i].value;
		en++;
	}
	
	if(en==num-1){
		return sum;
	}
	return -1;
	
}

int main(){

    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin>>n;
	
	map=vector<vector<int>>(n,vector<int>(n,0));
	edgenum=vector<vector<int>>(n,vector<int>(n,0));
	num=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>map[i][j];
			if(map[i][j]==1||map[i][j]==2){
				edgenum[i][j]=++num;
			}
			
		}
	}

	
	p=vector<int>(num+1);
	for(int i=0;i<num+1;i++){
		p[i]=i;
	}
	int f=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(map[i][j]==1||map[i][j]==2){
				
				bfs(i,j);
			}
			
		}
	}
	
	cout<<solve();
	
}