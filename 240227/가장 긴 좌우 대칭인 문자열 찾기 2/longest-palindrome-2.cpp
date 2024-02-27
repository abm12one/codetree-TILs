#include <iostream>
#include <string>
#include <algorithm>

#define MAX_N 200001

using namespace std;

// 변수 선언
string temp, input_str;
int n;

// A : i번지를 중심으로 하는 홀수 길이의 팰린드롬 중 
//     가장 긴 팰린드롬의 반지름의 길이
// 즉, [i - A[i], i + A[i]]가 i를 중심으로 하는 최장 팰린드롬이 됩니다.
int A[MAX_N];

int main() {
    // 입력:
    string temp;
    cin >> temp;

    // Manacher's algorithm을 적용하기 위해
    // 주어진 문자열 내 문자 사이사이에 #을 넣어줍니다.    
    for(int i = 0; i < (int) temp.size(); i++) {
        input_str += "#";
        input_str += temp[i];
    }
    input_str += "#";

    // Manacher's algorithm을 진행해봅니다.
    n = (int) input_str.size();
    int r = -1, p = -1;
    // r : j < i를 만족하는 j들 중 max(j + A[j]) 값을 기록합니다.
    // p : max(j + A[j]) 가 되는 j의 값을 기록합니다.
    for(int i = 0; i < n; i++) {
        // 만약 r값이 i보다 작다면
        // 줄일 수 있는 부분이 없으므로
        // A[i] = 0으로 시작합니다.
        if(r < i)
            A[i] = 0;
        // r값이 i보다 같거나 크다면
        // i를 p로부터 대칭시켰을 때의 위치인 ii에 대해
        // 이미 계산된 A[ii]값을 이용하여
        // i를 중심으로 뻗어나갈 수 있는 적절한 초기값을 
        // O(1)에 정해줄 수 있습니다.
        else {
            int ii = 2 * p - i;
            A[i] = min(r - i, A[ii]);
        }

        // i를 중심으로 최대로 뻗어나갑니다.
        while(i - A[i] - 1 >= 0 && i + A[i] + 1 < n && 
              input_str[i - A[i] - 1] == input_str[i + A[i] + 1])
            A[i]++; 

        // i + A[i] 중 최대가 선택되도록
        // r, p값을 갱신해줍니다.
        if(i + A[i] > r) {
            r = i + A[i];
            p = i;
        }
    }

    // 최장 팰린드롬의 길이를 계산합니다.
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, 2 * A[i] + 1);
    
    // 처음 주어진 문자열에서 
    // #을 제외한 부분의 길이가 실제 답이 되기에
    // 2로 나눴을 때의 몫이 답이 됩니다.
    cout << ans / 2;
    return 0;
}