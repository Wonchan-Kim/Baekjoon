#include <iostream>
using namespace std;

int main() {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    long long b_copy = b;
    long long d_copy = d;
    int b_len = 0;
    int d_len = 0;

    while (b_copy > 0) {
        b_copy /= 10;
        b_len++;
    }

    while (d_copy > 0) {
        d_copy /= 10;
        d_len++;
    }

    while (d_len) {
        c *= 10;
        d_len--;
    }

    while (b_len) {
        a *= 10;
        b_len--;
    }

    a += b;
    c += d;

    cout << a + c << endl;

    return 0;
}
