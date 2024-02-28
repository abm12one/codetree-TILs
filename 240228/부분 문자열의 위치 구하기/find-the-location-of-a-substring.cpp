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

string t,part;

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
	
	cin>>t>>part;
	
    n = (int) t.size();
    l = (int) part.size();

    for(int k = 0; k < 2; k++) {
        
        p_pow[k][0] = 1;
        for(int i = 1; i <= n; i++)
            p_pow[k][i] = (p_pow[k][i - 1] * p[k]) % m[k];
    }

    long long p_h[2] = {};
    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < l; i++)
            p_h[k] = (p_h[k] + ToInt(part[i]) * p_pow[k][l - 1 - i]) % m[k];
    }
   
    long long t_h[2] = {};
    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < l; i++)
            t_h[k] = (t_h[k] + ToInt(t[i]) * p_pow[k][l - 1 - i]) % m[k];
    }

    int exists = 0;
    int st;
    if(p_h[0] == t_h[0] && p_h[1] == t_h[1]){
		exists = 1;
		st=0;
	}
      

    for(int i = 1; i <= n - l; i++) {
        for(int k = 0; k < 2; k++) {
            
            t_h[k] = (t_h[k] * p[k] - ToInt(t[i - 1]) * p_pow[k][l] + ToInt(t[i + l - 1])) % m[k];
            
            if(t_h[k] < 0)
                t_h[k] += m[k];
        }

        // 값이 일치한다면 존재하는 것입니다.
        if(p_h[0] == t_h[0] && p_h[1] == t_h[1]){
			exists = 1;
			st=i;
		}
            
		
    }

    if(exists)
        cout << st;
    else
        cout << -1;
    return 0;
}