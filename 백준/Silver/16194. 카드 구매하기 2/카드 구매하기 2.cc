#include <iostream>
#include <algorithm>
using namespace::std;

int arr[1001] = {0};
int dp[1001] ={0};
int main(){
    int input;
    cin >> input;
    for(int i = 1; i <= input;  i++){
        cin >> arr[i];
        dp[i] = arr[i];
    }
    for(int i = 2; i <= input; i++){
        for(int j = 1; j <= i; j++){
            dp[i] = min(dp[i], dp[i - j] + arr[j]);
        }
    }
    cout << dp[input] << endl;

}