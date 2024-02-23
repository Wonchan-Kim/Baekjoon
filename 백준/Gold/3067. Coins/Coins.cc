#include <iostream>
#include <vector>
#include <string.h> // For memset

using namespace std;

int dp[10001];

int bottomTop(vector<int>& value, int n, int m){
    memset(dp, 0, sizeof(dp)); // Reset dp array for each call
    dp[0] = 1; // Base case: there's one way to make 0, which is to use no coins
    for(int i = 0; i < n; i++){ // Corrected indexing to start from 0
        for(int j = value[i]; j <= m; j++){
            dp[j] += dp[j-value[i]];
        }
    }
    return dp[m];
}

int main() {
    int t;
    cin >> t;
    while(t--){
        int n; // type of coins
        cin >> n;
        vector<int> value(n); // Pre-size the vector to n
        for(int i = 0; i < n; i++){
            cin >> value[i];
        }
        int m; // Target value
        cin >> m;
        cout << bottomTop(value, n, m) << endl;
        // No need to memset here since it's done at the beginning of bottomTop
    }
}
