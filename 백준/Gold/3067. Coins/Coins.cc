#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

int dp[10001];

int bottomTop(vector<int>& value, int n, int m){
    dp[0] = 1;
    for(int i = 0; i < n; i++){
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
        vector<int> value(n);
        for(int i = 0; i < n; i++){
            cin >> value[i];
        }
        int m; //target value
        cin >> m;
        cout << bottomTop(value, n, m) << endl;
        memset(dp,0,sizeof(dp));
    }
}