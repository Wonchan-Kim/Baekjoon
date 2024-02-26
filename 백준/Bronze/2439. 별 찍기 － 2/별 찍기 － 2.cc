#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string empty;
    string star;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j < n - i; j++)
            empty += ' ';
        for(int k = 0; k < i; k++)
            star += '*';
        if(i != n)
            cout << empty << star << endl;
        else
            cout << empty << star;
        empty = "";
        star = "";
    }
}