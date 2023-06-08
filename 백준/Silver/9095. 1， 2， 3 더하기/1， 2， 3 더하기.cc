#include <iostream>

using namespace::std;
int arr[12] {0} ;
int main(){
    arr[1] = 1;
    arr[2] = 2;
    arr[3] = 4;

    int input;
    cin >> input;

    for(int i = 0; i < input; i++){
        int ans;
        cin >> ans;
        for(int j = 4; j <= ans; j++){
            arr[j] = arr[j-1] + arr[j-2] + arr[j-3];
        }
        cout << arr[ans] << endl;
    }
}
