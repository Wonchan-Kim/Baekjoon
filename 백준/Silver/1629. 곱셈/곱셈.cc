#include <iostream>
#include <math.h>
using namespace std;

long long DAC(int A, int B, int C){
    if(B == 1)
        return A%C;
    if (B % 2 == 0){
        return DAC(A%C, B/2, C) * DAC(A%C, B/2, C) % C;
    }
    else {
        return DAC(A%C, B/2, C) * DAC(A%C, B/2, C) % C * A%C;
    }
}

int main() {
    //get A,B,C
    int A,B,C;
    cin >> A >> B >> C;
    //call helper function
    cout << DAC(A,B,C) << endl;
}