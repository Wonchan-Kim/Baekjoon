#include <iostream>
#include <cmath>

using namespace std;

bool is_prime(int a) {
    if (a < 2) {
        return false;
    }
    int sqrt_n = sqrt(a);
    for (int i = 2; i <= sqrt_n; i++) {
        if (a % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int num;
    cin >> num;
    int ans = 0;
    for (int i = 0; i < num; i++) {
        int input;
        cin >> input;
        if (is_prime(input)) {
            ans++;
        }
    }
    cout << ans;

    return 0;
}
