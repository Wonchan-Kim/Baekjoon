#include <iostream>

using namespace std;

#define INF 1e9

const int MAX = 101; // 노드의 최대 개수 설정 (문제에 따라 조정)

int dp[MAX][MAX];

int main() {
    int n, m;
    cin >> n >> m;

    // 초기화
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            dp[i][j] = INF;
        }
    }

    // 자기 자신으로 가는 거리는 0으로 설정
    for (int i = 1; i <= n; i++) {
        dp[i][i] = 0;
    }

    // 간선 입력
    for (int i = 0; i < m; i++) {
        int x, y, dis;
        cin >> x >> y >> dis;
        if(dp[x][y] > 0 && dp[x][y] < dis)
            continue;
        dp[x][y] = dis;
    }

    // 플로이드 워셜 알고리즘
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dp[i][k] < INF && dp[k][j] < INF) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dp[i][j] == INF) {
                cout << 0 << ' ';
            } else {
                cout << dp[i][j] << ' ';
            }
        }
        cout << endl;
    }

    return 0;
}
