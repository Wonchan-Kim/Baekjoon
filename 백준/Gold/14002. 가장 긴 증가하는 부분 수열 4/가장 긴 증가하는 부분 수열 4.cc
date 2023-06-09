#include <iostream>
#include <stack>
using namespace::std;

int main(){
    int arr[1001];
    int change[1001] ={ 0 };
    int temp = 0;
    stack<int> ans_;
    int input;
    cin >> input;
    for(int i = 0; i < input; i++){
        cin >> arr[i];
    }

    int dp[1002];
    for(int i = 0; i < 1002; i++)
        dp[i] = 1;
    //각 DP[i]의 값에는 그 인덱스 값의 길에 해당하는 최장 길이가 저장된다.
    for(int i = 1; i <= input; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], (dp[j] + 1));
                temp = dp[i]; 
                }
        }
    }
    int ans = 0;

    for(int i = 0; i < input; i++)
    {
        ans = max(ans, dp[i]);
        temp = ans;
    }
    cout << ans << endl;
    int i = input -1;
    while(temp != 0) {
        if(dp[i] == temp){
            ans_.push(arr[i]);
            temp--;
            i--;
        }
        else{
            i--;
        }
    }
    while(!ans_.empty()){
        cout << ans_.top() << ' ';
        ans_.pop();
    }
    return 0;
}