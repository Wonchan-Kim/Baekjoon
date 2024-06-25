#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> arr;
vector<int> ans;

void solve() {
    int j = 0;
    for(int i = 1; i < n; i++) {
        if(ans[j] < arr[i]) {
            ans.push_back(arr[i]);
            j++;
        } else {
            int pos = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
            ans[pos] = arr[i];
        }
    }
}

int main() {
    cin >> n;
    if (n <= 0) {
        cout << 0 << endl;
        return 0;
    }

    arr.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    ans.push_back(arr[0]);
    solve();
    cout << ans.size() << endl;
    return 0;
}