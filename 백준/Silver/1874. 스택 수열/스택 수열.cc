#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> target(n);
    for (int i = 0; i < n; i++) {
        cin >> target[i];
    }

    vector<char> operations;
    stack<int> st;
    int current = 1;

    for (int i = 0; i < n; i++) {
        while (current <= target[i]) {
            st.push(current);
            operations.push_back('+');
            current++;
        }

        if (st.top() == target[i]) {
            st.pop();
            operations.push_back('-');
        } else {
            cout << "NO" << endl;
            return 0;
        }
    }

    for (int i = 0; i < operations.size(); i++) {
        cout << operations[i] << '\n';
    }

    return 0;
}
