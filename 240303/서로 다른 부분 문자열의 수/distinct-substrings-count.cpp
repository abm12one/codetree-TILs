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
#define MAX_N 100000

using namespace std;

// 변수 선언
string s;

int n;
int ans=0;
// 2개의 polynomial rolling 해싱을 위한 p, m 값을 정의합니다.
int p[2] = {31, 37};
int m[2] = {int(1e9) + 7, int(1e9) + 9};

// p^i, 값을 m으로 나눈 나머지를 관리합니다.
long long p_pow[2][MAX_N + 1];

// 소문자 알파벳을 수로 변경합니다.
int ToInt(char c) {
    return c - 'a' + 1;
}

// 길이가 l인 부분 문자열 중 2번 이상 등장하는 경우가 있는지 확인합니다.
void Exists(int l) {
	set<pair<long long, long long> > hs;
    // p_pow 값을 계산합니다.
   
    long long h[2] = {};
    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < l; i++)
            h[k] = (h[k] + ToInt(s[i]) * p_pow[k][l - 1 - i]) % m[k];
    }

    // set에 넣어줍니다.
    if(hs.find(make_pair(h[0], h[1])) == hs.end()){
	   hs.insert(make_pair(h[0], h[1]));
    }
	
    // [i, i + l - 1] 구간을 부분문자열로 하는 경우를 전부 탐색합니다.
    for(int i = 1; i <= n - l; i++) {
        for(int k = 0; k < 2; k++) {
            // hash 값을 갱신해줍니다.
            h[k] = (h[k] * p[k] - ToInt(s[i - 1]) * p_pow[k][l] + ToInt(s[i + l - 1])) % m[k];
            // 값을 양수로 변환해줍니다.
            if(h[k] < 0)
                h[k] += m[k];
        }

        // 이미 동일한 해싱값이 존재한다면
        // 2번 이상 등장하는 것입니다.
        if(hs.find(make_pair(h[0], h[1])) != hs.end()) continue;

        hs.insert(make_pair(h[0], h[1]));
    }
	ans+=hs.size();
	return;

  
}

int main() {
    // 입력:
    cin >> s;

    n = (int) s.size();
	for(int k = 0; k < 2; k++) {
        // p_pow[i] = p^i % m
        p_pow[k][0] = 1;
        for(int i = 1; i <= n; i++)
            p_pow[k][i] = (p_pow[k][i - 1] * p[k]) % m[k];
    }

    for(int i=1;i<=n;i++){
		Exists(i);
	}

    cout << ans;
    return 0;
}