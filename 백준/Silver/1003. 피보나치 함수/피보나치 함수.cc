#include <iostream>
#include <vector>

using namespace std;
struct fibonacci {
    int zero = 0;
    int first = 0;
};

fibonacci get(int n, vector<fibonacci> arr) {
    if(n == 0)
        arr[n].zero++;
    else if(n == 1)
        arr[n].first++;
    else {
        arr[0].zero = 1;
        arr[0].first = 0;
        arr[1].zero = 0;
        arr[1].first = 1;
        for(int i = 2; i <= n; i++){
            arr[i].zero = arr[i-1].zero + arr[i-2].zero;
            arr[i].first = arr[i-1].first + arr[i-2].first;
        }
    }
    return arr[n];
}
int main() {
    int t;
    cin >> t;
    vector<fibonacci> arr;
    while(t--) {
        int n;
        cin >> n;
        arr.resize(n+1);
        fibonacci ans = get(n, arr);
        cout << ans.zero << ' ' << ans.first << endl;
    }
}