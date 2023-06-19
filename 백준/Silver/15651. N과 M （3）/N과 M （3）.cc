#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> store;

void backtracking(int len) {
    if (len == M) {
        for (int i = 0; i < len; i++) {
            cout << store[i] << ' ';
        }
        cout << '\n';
    } else {
        for (int i = 1; i <= N; i++) {
            store.push_back(i);
            backtracking(len + 1);
            store.pop_back();
        }
    }
}

int main() {
    cin >> N >> M;
    backtracking(0);
    return 0;
}
