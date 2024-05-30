#include <iostream>

using namespace std;

long long int arr[2][2] = {{1, 1}, {1, 0}};
long long int result[2][2] = {{1, 0}, {0, 1}}; // 단위 행렬
void multiply(long long int A[2][2], long long int B[2][2]) {
    long long int x = (A[0][0] * B[0][0] % 1000000007 + A[0][1] * B[1][0] % 1000000007) % 1000000007;
    long long int y = (A[0][0] * B[0][1] % 1000000007 + A[0][1] * B[1][1] % 1000000007) % 1000000007;
    long long int z = (A[1][0] * B[0][0] % 1000000007 + A[1][1] * B[1][0] % 1000000007) % 1000000007;
    long long int w = (A[1][0] * B[0][1] % 1000000007 + A[1][1] * B[1][1] % 1000000007) % 1000000007;

    A[0][0] = x;
    A[0][1] = y;
    A[1][0] = z;
    A[1][1] = w;
}

void power(long long int F[2][2], long long int n) {
    if (n == 0 || n == 1)
        return;
    long long int M[2][2] = {{1, 1}, {1, 0}};

    power(F, n / 2);
    multiply(F, F);

    if (n % 2 != 0)
        multiply(F, M);
}
long long int fibo(long long int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    long long int F[2][2] = {{1,1}, {1,0}};
    power(F, n-1);
    return F[0][0];
}

int main() {
    long long int n;
    cin >> n;
    cout << fibo(n) % 1000000007 << endl;
}