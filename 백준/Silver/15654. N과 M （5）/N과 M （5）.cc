#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int M, N;
int arr[9];
vector<int> store;
bool checked[9];

void backtracking(int len) {
    if (len == N) {
        for (int i = 0; i < len; i++) {
            cout << store[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < M; i++) {
        if (!checked[i]) {
            store.push_back(arr[i]);
            checked[i] = true;
            backtracking(len + 1);
            store.pop_back();
            checked[i] = false;
        }
    }
}

int main() {
    cin >> M >> N;
    for (int i = 0; i < M; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + M);
    backtracking(0);
    return 0;
}
