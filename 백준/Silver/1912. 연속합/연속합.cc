#include <iostream>
using namespace std;

int dp[100001];
int arr[100001];

int main() {
    int input;
    cin >> input;

    for (int i = 0; i < input; i++) {
        cin >> arr[i];
        dp[i] = arr[i];
    }

    int ans = dp[0];
    for (int i = 1; i < input; i++) {
        dp[i] = max(dp[i], dp[i - 1] + arr[i]);
        ans = max(ans, dp[i]);
    }

    cout << ans << endl;

    return 0;
}
