#include <iostream>
#include <algorithm>

using namespace std;

int arr[10001];
int dp[10001];

int main() {
    int input;
    cin >> input;

    for (int i = 1; i <= input; i++) {
        cin >> arr[i];
    }

    dp[1] = arr[1];
    dp[2] = arr[1] + arr[2];

    for (int i = 3; i <= input; i++) {
        dp[i] = max({dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]});
    }

    cout << dp[input] << endl;

    return 0;
}
