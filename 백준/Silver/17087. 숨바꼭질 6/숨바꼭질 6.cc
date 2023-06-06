#include <cmath>
#include <iostream>
using namespace::std;
int gcd(int a, int b){
    return b? gcd(b, a%b) : a;
}
int main(){
    int arr[100001] = { -1 };
    int a, b;
    int key = 0;
    cin >> a >> b;
    for(int i = 0; i < a; i++){
        cin >> arr[i];
    }
    for(int i = 0 ; i < a; i++){
        key = gcd(key, abs(b-arr[i]));
    }
    cout << key << endl;
}