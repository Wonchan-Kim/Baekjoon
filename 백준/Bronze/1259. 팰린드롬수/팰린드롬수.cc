#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    string s;
    while (1) {
        cin >> s;
        if (s == "0")
            break;

        stack<char> S;
        queue<char> Q;

        for (int i = 0; i < s.size(); i++) {
            S.push(s[i]);
            Q.push(s[i]);
        }

        bool isPalindrome = true;
        while (!S.empty()) {
            char peek = S.top();
            char front = Q.front();
            S.pop();
            Q.pop();
            if (peek != front) {
                isPalindrome = false;
                break;
            }
        }

        if (isPalindrome) {
            cout << "yes" << endl;
        } else {
            cout << "no" << endl;
        }
    }
    return 0;
}
