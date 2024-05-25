#include <iostream>
#include <cstring>

using namespace std;

int dp[31][8];

int f(int n, int bit) // n is current stage, bit represents current status
{
    if (n < 0) return 0;
    if (n < 1) return bit == 0;
    int &r = dp[n][bit];
    if(r != -1) return r;

    r = 0;
    if(bit == 0) {
        r += f(n-1, 1);
        r += f(n-2, 0);
        r += f(n-1, 4);
    }
    if(bit == 1){
        r += f(n-1, 6);
        r += f(n-1, 0);
    }
    if(bit == 2){
        r += f(n-1, 5);
    }
    if(bit == 3){
        r += f(n-1, 4);
    }
    if(bit == 4) {
        r += f(n-1, 0);
        r += f(n-1, 3);
    }
    if(bit == 5) {
        r += f(n-1, 2);

    }
    if(bit == 6) {
        r += f(n-1, 1);
    }
    return r;
}



int main() {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    cout << f(n, 0) << endl;
}