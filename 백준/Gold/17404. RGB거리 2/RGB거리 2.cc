#include <iostream>
#include <algorithm>
using namespace std;

int n;
int ans = 987654311;
int dp[1001][3];
int cost[1001][3];
int main() {    
    cin >> n;
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;

    for(int i = 1; i <= n; i++){
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    
    for(int k = 0; k <= 2; k++){
        for(int i = 0; i <= 2; i++){
            if(i == k)
                dp[1][k] = cost[1][k];
            else
                dp[1][i] = 987654321;
        }

        for(int i = 2; i <= n; i++){
            dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + cost[i][0];
            dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + cost[i][1];
            dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + cost[i][2];
        }

        for(int i = 0; i <= 2; i++){
            if(i == k) continue;
            ans = min(ans, dp[n][i]);
        }
    }
    cout << ans << endl;
}