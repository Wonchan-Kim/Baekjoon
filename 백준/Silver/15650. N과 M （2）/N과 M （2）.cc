#include <iostream>
#include <vector>

using namespace std;

vector<int> vec;
int n;
int m;

void backtrack(int len) {
    if (len == m - 1) {
        for (int i = 0; i < len; i++) {
            cout << vec[i] << ' ';
        }
        cout << vec[len] << endl;
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (i <= vec[len]) {
            continue;
        } else {
            vec.push_back(i);
            backtrack(len + 1);
            vec.pop_back();
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
        backtrack(0);
        vec.pop_back();
    }
    return 0;
}
