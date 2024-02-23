#include <iostream>
#include <algorithm>
using namespace std;

struct item{
    int weight;
    int value;
};

int dp [101][100001];
int knapsack(vector<item>& arr, int n, int k){
    for(int i = 0; i <= n; ++i) {
        for(int j = 0; j <= k; ++j) {
            dp[i][j] = 0;
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            if(arr[i-1].weight <= j)
                dp[i][j] = max(dp[i-1][j], arr[i-1].value + dp[i-1][j-arr[i-1].weight]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][k];
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<item> arr;
    for(int i = 0; i < n; i++){
        item item;
        cin >> item.weight >> item.value;
        arr.push_back(item);
    }
    cout << knapsack(arr,n,k) << endl;
    return 0;
}