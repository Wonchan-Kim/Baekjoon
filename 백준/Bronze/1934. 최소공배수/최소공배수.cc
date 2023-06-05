#include <iostream>

using namespace::std;

int gcd(int a, int b){
    return b? gcd(b, a%b) : a;
}

int lcm(int a, int b){
    return (a*b)/gcd(a, b);
}

int main(){
    int a;
    cin >> a;

    for(int i = 0; i < a; i++){
        int a;
        int b;
        cin >> a;
        cin >> b;

        cout << lcm(a,b) << endl;
    }
}