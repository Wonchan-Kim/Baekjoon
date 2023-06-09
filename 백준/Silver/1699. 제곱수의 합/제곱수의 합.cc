#include <iostream>
#include <algorithm>
#include <vector>

using namespace::std;
using std::vector;

int main()
{
    int n;
    cin >> n;
    vector<int> dp(n+1);
    for(int i = 1; i <= n; i++)
        dp[i] = i;
    for(int i = 4; i <=n; i++)
    {
        for(int j = 1; j * j <= i; j++)
            dp[i] = min(dp[i], dp[i-(j*j)] + 1);
    }
    cout << dp[n] << endl;
    return 0;
    
}