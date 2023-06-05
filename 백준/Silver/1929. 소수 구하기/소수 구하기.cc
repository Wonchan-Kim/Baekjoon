#include <cmath>
#include <iostream>
using namespace::std;

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

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(0);
    int a, b;
    cin >> a >> b;

    for(int i = a; i <=b; i ++){
        if(is_prime(i))
            cout << i << '\n';
    }
}