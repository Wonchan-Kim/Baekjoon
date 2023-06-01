#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    stack<char> left_stk;
    stack<char> right_stk;

    // Initialize the left stack with the characters from the input string
    for (char ch : s) {
        left_stk.push(ch);
    }

    int cnt;
    cin >> cnt;
    while (cnt--) {
        char cmd;
        cin >> cmd;

        if (cmd == 'L') {
            if (!left_stk.empty()) {
                right_stk.push(left_stk.top());
                left_stk.pop();
            }
        } else if (cmd == 'D') {
            if (!right_stk.empty()) {
                left_stk.push(right_stk.top());
                right_stk.pop();
            }
        } else if (cmd == 'B') {
            if (!left_stk.empty()) {
                left_stk.pop();
            }
        } else if (cmd == 'P') {
            char ch;
            cin >> ch;
            left_stk.push(ch);
        }
    }

    // Transfer the remaining characters from the left stack to the right stack
    while (!left_stk.empty()) {
        right_stk.push(left_stk.top());
        left_stk.pop();
    }

    // Print the characters in the right stack, in the correct order
    while (!right_stk.empty()) {
        cout << right_stk.top();
        right_stk.pop();
    }

    return 0;
}
