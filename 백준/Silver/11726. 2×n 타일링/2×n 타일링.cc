#include <iostream>
using namespace::std;
int dp[1005] = { 0 };

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    int n;
    cin >> n;
    for(int i = 3; i<=n; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
        dp[i] = dp[i] % 10007;
    }
    cout << dp[n] << endl;
    
}