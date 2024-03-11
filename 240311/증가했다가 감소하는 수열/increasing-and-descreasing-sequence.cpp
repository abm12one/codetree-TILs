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
#include<unordered_set>
#include<set>
#define MAX_N 200


using namespace std;

const int MOD = 10007;


int n;
int points[MAX_N];


int dp[MAX_N][MAX_N];

int main() {
    
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> points[i];

    
    dp[0][0] = 1;

    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            
            int next = max(i, j) + 1;

            if(next == n)
                continue;

            
            for(int k = next; k < n; k++) {

                if(k == n - 1) {
                    if(points[i] < points[k] && points[j] < points[k]) {
                        dp[k][j] += dp[i][j];
                        dp[k][j] %= MOD;

                        dp[i][k] += dp[i][j];
                        dp[i][k] %= MOD;
                    }
                    break;
                }
                if(points[i] < points[k]) {
                    dp[k][j] += dp[i][j];
                    dp[k][j] %= MOD;
                }

                
                if(points[j] < points[k]) {
                    dp[i][k] += dp[i][j];
                    dp[i][k] %= MOD;
                }
                
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += dp[i][n - 1];
        ans %= MOD;
    }

    cout << ans;
    return 0;
}