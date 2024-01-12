//
// Created by wonchan kim on 1/12/24.
//
#include <iostream>

using namespace std;
long long factorial(int n){
    if(n == 0)
        return 1;
    if(n == 1)
        return 1;
    return n * factorial(n-1);
}
int main(){
    int T;
    cin >> T;
    while(T) {
        int N;
        int M;
        long long ans = 1;

        cin >> N >> M;
        for (int i = 0; i < N; i++) {
            ans *= M - i;
            ans /= i + 1;
        }
        cout << ans << endl;
        T--;
    }
    return 0;
}
