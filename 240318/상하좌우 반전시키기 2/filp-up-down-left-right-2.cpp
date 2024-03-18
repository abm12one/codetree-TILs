#include <iostream>

#define MAX_N 100
#define MAX_M 10

using namespace std;

const int dx[5] = {0, -1, 0, 1, 0}, dy[5] = {0, 0, -1, 0, 1};

// 변수 선언
int n, m;
int board[MAX_N + 1][MAX_M + 1];
int board_original[MAX_N + 1][MAX_M + 1];

bool isOutrange(int x, int y) {
    return !(1 <= x and x <= n and 1 <= y and y <= m);
}

int ans = 1e9;

int main() {
    // 입력:
    cin >> n >> m;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            cin >> board[i][j];
    
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
            board_original[i][j] = board[i][j];

    // 1번째 행을 2^m가지의 방법으로 모든 방법을 눌러봅니다.
    // 그 다음부터는 2번째 행은 1번 행을 전부 1로 만들기 위해 방법이 제한됩니다.
    // 이를 바탕으로 최소 횟수를 구해 보겠습니다.
    for(int state = 0; state < (1 << m); state++) {
        // board를 초기화합니다.
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= m; j++)
                board[i][j] = board_original[i][j];

        // 우선 2^m가지의 방법으로 모두 눌러보고 그에 맞게 board를 바꿔줍니다.
        for(int y = 1; y <= m; y++) {
            if((state >> (y - 1)) & 1) {
                int x = 1;
                for(int dir = 0; dir < 5; dir++) {
                    int nx = x + dx[dir];
                    int ny = y + dy[dir];

                    if(isOutrange(nx, ny)) continue;

                    board[nx][ny] = 1 - board[nx][ny];
                }
            }
        }

        // 해당 방법으로 눌렀을 때
        // 숫자를 눌러야 할 횟수를 num에 기록합니다.
        int num = 0;
        for(int y = 1; y <= m; y++) {
            if((state >> (y - 1)) & 1)
                num++;
        }

        // 2번 행부터 차근차근 버튼을 눌러봅니다.
        int cnt = 0;
        for(int i = 2; i <= n; i++)
            for(int j = 1; j <= m; j++) {
                // board[i - 1][j]가 0이면 누릅니다.
                if(board[i - 1][j] == 0) {
                    num++;
                    for(int dir = 0; dir < 5; dir++) {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        if(isOutrange(nx, ny))
                            continue;
                        
                        board[nx][ny] = 1 - board[nx][ny];
                    }
                }
            }
        
        // 다 채워졌는지 확인합니다.
        bool full_filled = true;
        for(int j = 1; j <= m; j++)
            if(!board[n][j]) full_filled = false;
        
        if(full_filled)
            ans = min(ans, num);
    }

    // 숫자를 모두 1로 만들기 위해 눌러야 할 최소 횟수를 출력합니다.
    // 만약 만드는 것이 불가능하다면 -1을 출력합니다.
    if(ans == 1e9)
        cout << -1;
    else
        cout << ans;

    return 0;
}