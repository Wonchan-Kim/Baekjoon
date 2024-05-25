#include <iostream>
#include <cstring>

using namespace std;

int dp[1000][13];

int DP(int n, int bit) {
    if (n < 0) return 0;
    if (n < 1) return bit == 0;
    int &r = dp[n][bit];
    if (r != -1) return r;

    r = 0;
    if (bit == 0){
        r += DP(n-1, 0);
        r += DP(n-1, 3);
        r += DP(n-1, 9);
        r += DP(n-1, 12);
        r += DP(n-2, 0);
    }
    if (bit == 3) {
        r += DP(n-1, 0);
        r += DP(n-1,12);
    }
    if(bit == 6){
        r += DP(n-1, 9);
    }
    if (bit == 9) {
        r += DP(n-1, 0);
        r += DP(n-1, 6);
    }
    if (bit == 12) {
        r += DP(n-1, 0);
        r += DP(n-1, 3);
    }
    return r;
}

int main() {
    int t, n;
    cin >> t;
    memset(dp, -1, sizeof(dp));
    while(t--){
        cin >> n;
        cout << DP(n, 0) << endl;
    }
}