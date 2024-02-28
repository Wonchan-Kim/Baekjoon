#include <deque>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void fill_array(string str, deque<int>& fill) {
    int num = 0;
    bool isNum = false;
    for (char c : str) {
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            isNum = true;
        } else if (isNum) {
            fill.push_back(num);
            num = 0;
            isNum = false;
        }
    }
    if (isNum) fill.push_back(num); 
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string command, input;
        int n;
        cin >> command >> n >> input;
        deque<int> dq;
        fill_array(input, dq);

        bool isError = false;
        bool isReverse = false;

        for (char cmd : command) {
            if (cmd == 'R') {
                isReverse = !isReverse;
            } else { // cmd == 'D'
                if (dq.empty()) {
                    isError = true;
                    cout << "error\n";
                    break;
                } else {
                    if (!isReverse) {
                        dq.pop_front();
                    } else {
                        dq.pop_back();
                    }
                }
            }
        }

        if (!isError) {
            cout << "[";
            while (!dq.empty()) {
                if (!isReverse) {
                    cout << dq.front();
                    dq.pop_front();
                } else {
                    cout << dq.back();
                    dq.pop_back();
                }
                if (!dq.empty()) cout << ",";
            }
            cout << "]\n";
        }
    }
    return 0;
}
