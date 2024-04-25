#include <iostream>
#include <algorithm>
#include <tuple>
#include <climits>

#define MAX_N 1000
#define MAX_R 1000
#define MAX_Q 4

using namespace std;

// 변수 선언
int n;
pair<int, int> points[MAX_N];

int ans = INT_MAX;

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);
    }

    // x 기준 오름차순으로 정렬합니다.
    sort(points, points + n);

    // y = b를 먼저 설정합니다.
    for(int b = 0; b <= MAX_R; b += 2) {
        // 1, 2, 3, 4 각 사분면에 
        // 들어 있는 점의 개수를 관리합니다.
        int cnt[MAX_Q + 1] = {};

        // 먼저 x = 0일 때의
        // 1, 2, 3, 4 각 사분면에
        // 있는 점의 수를 계산합니다. 
        // 모든 점은 x = 0 보다 오른쪽에 있으므로
        // 이는 y좌표에 따라 1, 4 사분면으로 나뉘게 됩니다.
        for(int i = 0; i < n; i++) {
            int y;
            tie(ignore, y) = points[i];

            if(y > b)
                cnt[1]++;
            else
                cnt[4]++;
        }

        // 이제 x 기준 오름차순으로 정렬된 
        // n개의 점을 보며 
        // 각 점을 순서대로 왼쪽으로 보내며
        // 1 -> 2 사분면으로
        // 4 -> 3 사분면으로 점들의 위치를 보정해줍니다.
        for(int i = 0; i < n; i++) {
            // 새로운 x값이 시작되는 경우에는
            // 답을 갱신해줍니다.
            if(i == 0 || points[i].first != points[i - 1].first) {
                int max_cnt = 0;
                for(int j = 1; j <= MAX_Q; j++)
                    max_cnt = max(max_cnt, cnt[j]);

                ans = min(ans, max_cnt);
            }
        
            // i번 점의 위치를 보정해줍니다.
            int y;
            tie(ignore, y) = points[i];
            if(y > b) {
                cnt[1]--;
                cnt[2]++;
            }
            else {
                cnt[4]--;
                cnt[3]++;
            }
        }
    }
    cout << ans;
    return 0;
}