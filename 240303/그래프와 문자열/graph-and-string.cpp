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
#include<set>

#define MAX_N 500001

using namespace std;

string part;
vector<int>t;
int n, l;
int p[2] = {31, 37};
int m[2] = {int(1e9) + 7, int(1e9) + 9};

vector<long long>t_h;
vector<long long>p_h;
long long p_pow[2][MAX_N + 1];

typedef struct{
	int dest;
	int d;
}node;

vector<vector<node>>map;


int ToInt(char c) {
    return c - 'a' + 1;
}

int ans=0;

int check(vector<int>&t){
	t_h = vector<long long>(2);
	for(int k = 0; k < 2; k++) {
        for(int i = 0; i < l; i++)
            t_h[k] = (t_h[k] + t[i] * p_pow[k][l - 1 - i]) % m[k];
    }
	
	//cout<<p_h[0]<<" "<<t_h[0]<<' '<<p_h[1]<<" "<<t_h[1]<<'\n';
	
	if(p_h[0] == t_h[0] && p_h[1] == t_h[1]){
		ans++;
		return 1; 	
	}
	
	return 0;
	
}

void bfs(vector<int>&t,int now,int num){
	if(num==l){
		/*
		cout<<"now "<<now<<'\n';
		for(int i=0;i<l;i++){
			cout<<t[i]<<' ';
		}
		cout<<'\n';
		*/
		check(t);
		return;
	}
	
	for(int i=0;i<map[now].size();i++){
		int there=map[now][i].dest;
		int td=map[now][i].d;
		t[num]=td;
		bfs(t,there,num+1);
		t[num]=0;
	}
	return;
	
}




int main() {
    
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>n>>part;
	map=vector<vector<node>>(n+1,vector<node>());
	for(int i=0;i<n-1;i++){
		int a,b;
		char ch;
		cin>>a>>b>>ch;
		
		map[a].push_back(node{b,ToInt(ch)});
		
	}

	l = (int) part.size();
	t=vector<int>(l+1,0);
    
	for(int k = 0; k < 2; k++) {
        
        p_pow[k][0] = 1;
        for(int i = 1; i <= n; i++)
            p_pow[k][i] = (p_pow[k][i - 1] * p[k]) % m[k];
    }
	
    p_h = vector<long long>(2);
    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < l; i++)
            p_h[k] = (p_h[k] + ToInt(part[i]) * p_pow[k][l - 1 - i]) % m[k];
    }
   
	
	for(int i=1;i<=n;i++){

		bfs(t,i,0);
	}
	cout<<ans<<'\n';
	
    
}