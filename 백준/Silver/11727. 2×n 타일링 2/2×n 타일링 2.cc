#include <iostream>

using namespace::std;
int dp[1000];

int main()
{
    dp[1] = 1;
    dp[2] = 3;
    int n;
    cin >> n;
    for(int i = 3; i <= n ; i++)
    {
        dp[i] = (dp[i-1] % 10007 + 2* dp[i-2]%10007) % 10007;
    }
    cout << dp[n] << endl;
}