#include <iostream>
using namespace::std;

long long dp [91] = { 0 };

int main()
{
    int N;
    cin >> N;
    
    dp[1] = 1;
    dp[2] = 1;
    
    for(int cnt = 3; cnt <= N ; cnt++)
        dp[cnt] = dp[cnt-1]+dp[cnt-2];
    
    cout << dp[N] << endl;
}

