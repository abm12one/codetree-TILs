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
#include<map>
//#include < unordered_set>
#include<set>

#define MAX_N 100001

using namespace std;

string t,part;
map<pair<int,int>,int>mapp;

int n, l;
int p[2] = {31, 37};
int m[2] = {int(1e9) + 7, int(1e9) + 9};

long long p_pow[2][MAX_N + 1];

int ToInt(char c) {
    return c - 'a' + 1;
}

int main() {
    
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin>>l>>t;
	
    n = (int) t.size();

    for(int k = 0; k < 2; k++) {
        
        p_pow[k][0] = 1;
        for(int i = 1; i <= n; i++)
            p_pow[k][i] = (p_pow[k][i - 1] * p[k]) % m[k];
    }

   
    long long t_h[2] = {};
    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < l; i++)
            t_h[k] = (t_h[k] + ToInt(t[i]) * p_pow[k][l - 1 - i]) % m[k];
    }

    
    mapp[make_pair(t_h[0],t_h[1])]++;

    for(int i = 1; i <= n - l; i++) {
        for(int k = 0; k < 2; k++) {
            
            t_h[k] = (t_h[k] * p[k] - ToInt(t[i - 1]) * p_pow[k][l] + ToInt(t[i + l - 1])) % m[k];
            
            if(t_h[k] < 0)
                t_h[k] += m[k];
        }

        // 값이 일치한다면 존재하는 것입니다.
		mapp[make_pair(t_h[0],t_h[1])]++;
		
		
            
		
    }
	int ans=0;
	
	for(auto it=mapp.begin();it!=mapp.end();it++){
		ans=max(it->second,ans);
	}
    cout<<ans<<'\n';
}