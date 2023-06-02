#include <stack>
#include <string>
#include <iostream>

using namespace std;

int main() {
    stack<char> temp;
    string get;
    getline(cin, get);

    bool inTag = false;

    for (int i = 0; i < get.size(); i++) {
        if (get[i] == '<') {
            while (!temp.empty()) {
                cout << temp.top();
                temp.pop();
            }
            inTag = true;
            cout << get[i];
        } else if (get[i] == '>') {
            inTag = false;
            cout << get[i];
        } else if (inTag) {
            cout << get[i];
        } else if ((get[i] >= 'a' && get[i] <= 'z') || (get[i] >= '0' && get[i] <= '9')) {
            temp.push(get[i]);
        } else if (get[i] == ' ') {
            while (!temp.empty()) {
                cout << temp.top();
                temp.pop();
            }
            cout << ' ';
        }
    }

    while (!temp.empty()) {
        cout << temp.top();
        temp.pop();
    }

    return 0;
}
