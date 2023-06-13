#include <iostream>
#include <algorithm>

using namespace std;

int pyramid[501][501];
int dp[501][501];

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> pyramid[i][j];
        }
    }

    dp[0][0] = pyramid[0][0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + pyramid[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + pyramid[i][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + pyramid[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[n - 1][i]);
    }

    cout << ans << endl;

    return 0;
}
