#include <iostream>
#include <algorithm>
using namespace std;

int n, m, arr[8], res[8];

void func(int cnt) {
    if (cnt == m) {
        bool flag = true;
        for (int i = 0; i < m - 1; i++) {
            if (res[i] > res[i + 1]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < m; i++) {
                cout << res[i] << ' ';
            }
            cout << endl;
        }
        return;
    }

    int xx = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != xx) {
            res[cnt] = arr[i];
            xx = res[cnt];
            func(cnt + 1);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    func(0);

    return 0;
}
