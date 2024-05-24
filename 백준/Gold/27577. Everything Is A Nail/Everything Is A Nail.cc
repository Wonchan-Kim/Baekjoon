#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

typedef unsigned int uint;

const int MAX_N = 300300;
uint tasks[MAX_N] = {0};
int dp[MAX_N][3][8]; // dp 테이블

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    uint n;
    cin >> n;

    for (uint i = 0; i < n; ++i) {
        cin >> tasks[i];
    }

    // dp 배열 초기화
    memset(dp, -1, sizeof(dp));

    // 초기 상태 설정: 0번째 작업 이전에 어떤 작업도 수행하지 않은 상태
    for (int tool = 0; tool < 3; ++tool) {
        dp[0][tool][7] = 0; // 7은 모든 도구가 사용 가능함을 의미 (111 in binary)
    }

    // 동적 프로그래밍을 통해 최대 작업 수 계산
    for (uint i = 0; i < n; ++i) {
        for (int tool = 0; tool < 3; ++tool) {
            for (int mask = 0; mask < 8; ++mask) {
                if (dp[i][tool][mask] == -1) continue;

                // 현재 도구로 작업을 수행할 수 있는 경우
                if (tasks[i] == tool) {
                    dp[i + 1][tool][mask] = max(dp[i + 1][tool][mask], dp[i][tool][mask] + 1);
                }

                // 다른 도구로 작업을 수행할 수 있는 경우
                if (mask & (1 << tasks[i])) {
                    dp[i + 1][tasks[i]][mask & ~(1 << tool)] = max(dp[i + 1][tasks[i]][mask & ~(1 << tool)], dp[i][tool][mask] + 1);
                }

                // 작업을 건너뛸 수 있는 경우
                dp[i + 1][tool][mask] = max(dp[i + 1][tool][mask], dp[i][tool][mask]);
            }
        }
    }

    // 결과 계산
    int ans = 0;
    for (int tool = 0; tool < 3; ++tool) {
        for (int mask = 0; mask < 8; ++mask) {
            ans = max(ans, dp[n][tool][mask]);
        }
    }

    // 결과 출력
    cout << ans << '\n';
    return 0;
}