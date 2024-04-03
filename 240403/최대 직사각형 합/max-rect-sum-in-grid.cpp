#include <iostream>
#include <climits>

#define MAX_N 300

using namespace std;

// 변수 선언
int n;
int arr[MAX_N + 1][MAX_N + 1];
int prefix_sum[MAX_N + 1][MAX_N + 1];
int dp[MAX_N + 1];

// (x1, y1), (x2, y2) 직사각형 구간 내의 원소의 합을 반환합니다.
int GetSum(int x1, int y1, int x2, int y2) {
    return prefix_sum[x2][y2]     - prefix_sum[x1 - 1][y2] -
           prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
}

// 시작행이 x1, 끝 행이 x2인 직사각형 중
// 가능한 최대 합을 반환합니다.
int GetMaxArea(int x1, int x2) {
    // 시작행과 끝 행이 x1, x2로 정해지면,
    // 각 열마다 x1부터 x2까지 행에 적혀있는 숫자들을 누적했을 때
    // 마치 1차원에서 최대 연속 부분 수열의 합을 구하는 문제와 같아집니다.
    // 이는 동적계획법으로 간단히 해결이 가능합니다.
    for(int y = 1; y <= n; y++) {
        // y열에 있는 숫자들의 합을 구해줍니다.
        int value = GetSum(x1, y, x2, y);

        dp[y] = max(value, dp[y - 1] + value);
    }

    // dp 값 중 최댓값이 원하는 값이 됩니다.
    int max_area = INT_MIN;
    for(int y = 1; y <= n; y++)
        max_area = max(max_area, dp[y]);
    
    return max_area;
}

int main() {
    // 입력:
    cin >> n;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> arr[i][j];

    // 누적합 배열을 만들어줍니다.
    prefix_sum[0][0] = 0;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            prefix_sum[i][j] = prefix_sum[i - 1][j] + 
                               prefix_sum[i][j - 1] -
                               prefix_sum[i - 1][j - 1] +
                               arr[i][j];
    
    // 직사각형의
    // 시작 행과 끝 행을 결정합니다.
    // 각 쌍에 대해 가능한 직사각형 중
    // 최대 합을 계산해
    // 답과 비교하여 최댓값을 갱신해줍니다.
    int ans = INT_MIN;
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j++)
            ans = max(ans, GetMaxArea(i, j));
    
    cout << ans;
    return 0;
}