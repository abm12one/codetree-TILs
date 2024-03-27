#include <iostream>

#define MAX_N 10
#define MAX_K 100

using namespace std;

// 변수 선언
int n, m, kk;
int board[MAX_N + 1][MAX_N + 1];

// dp[i][j] : 
// 1번 행을 시작으로 i번 행까지 칸을 채웠을 때
// 각 i번 행에서 각 열마다 칸을 선택했는지 여부를
// x1, x2, ..., xk라 헀을 때 
// 2^x1 + 2^x2 + ... + 2^xk 값이 j라 하면 (bitmask된 정수값이 j)
// 해당 상태에서 조건에 맞게 선택하면서 얻을 수 있는 수들의 최대 합
int dp[MAX_N + 1][1 << MAX_N][MAX_K + 1];

int main() {
    // 입력:
    cin >> n >> m >> kk;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];

    // 뿌려주는 방식의 dp를 진행합니다.
    // dp[i][j]가 계산이 되어있다는 가정하에서
    // 그 다음 상태값을 갱신합니다.
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < (1 << m); j++) {
            for(int k = 0; k < (1 << m); k++) {
                // 그다음 줄의 state에 대해 해당 값을 만들 수 있는지 판단하고 답을 갱신해줍니다.
                
                // 두 값의 비트가 겹친다면
                // 상하로 인접한 칸이 있음을 의미하므로 패스합니다.
                if(k & j) continue;

                // k에서 연속된 두 비트의 값이 1이라면
                // 좌우로 인접한 칸이 있음을 의미하므로 패스합니다.
                bool is_overlap = false;
                for(int x = 0; x < m - 1; x++) {
                    if(((k >> x) & 1) && ((k >> (x + 1)) & 1))
                        is_overlap = true;
                }
                if(is_overlap) continue;

                // i + 1번째 줄에 추가로 선택되는 숫자의 총합 num,
                // 선택되는 숫자의 개수 총합 cnt를 계산해 준 뒤,
                // dp값을 갱신해줍니다.
                int num = 0;
                int cnt = 0;
                for(int x = 0; x < m; x++) {
                    if((k >> x) & 1) {
                        num += board[i + 1][x + 1];
                        cnt++;
                    }
                }

                for(int l = 0; l <= kk - cnt; l++) {
                    dp[i + 1][k][l + cnt] = max(dp[i + 1][k][l + cnt], dp[i][j][l] + num);
                }
            }
        }
    }

    // 선택할 수 있는 칸의 개수의 최댓값을 출력합니다.
    int ans = 0;
    for(int i = 0; i < (1 << m); i++) {
        for(int k = 0; k <= kk; k++)
            ans = max(ans, dp[n][i][k]);
    }
    cout << ans;

    return 0;
}