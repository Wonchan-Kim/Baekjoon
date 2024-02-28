#include <deque>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isnum(char c){
    return (c >= '0' && c<= '9');
}
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

void reverseQueue(deque<int>& source, deque<int>& temp){
    while(!source.empty()) {
        temp.push_back(source.back());
        source.pop_back();
    }
    source = temp;
}

int deleteQueue(deque<int>& source, int n, bool isReverse){
    if(isReverse == false) {
        while (n--) {
            if (source.empty()) {
                cout << "error" << endl;
                return -1;
            }
            source.pop_front();
        }
        return 1;
    }
    else{
        while (n--) {
            if (source.empty()) {
                cout << "error" << endl;
                return -1;
            }
            source.pop_back();
        }
        return 1;
    }
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string command;
        int n;
        string input;
        cin >> command >> n >> input;
        deque<int> source;
        deque<int> temp;
        fill_array(input, source);
        int result = 0;
        int cnt_R = 0;
        int cnt_D = 0;
        int i = 0;
        bool isReverse = false;
        while(command[i]){
            if(command[i] == 'R'){
                while(command[i] == 'R') {
                    cnt_R++;
                    i++;
                }
                if(cnt_R % 2) {
                    isReverse = !isReverse;
                }
                cnt_R = 0;
            }
            else if(command[i] == 'D') {
                while (command[i] == 'D') {
                    cnt_D++;
                    i++;
                }
                result = deleteQueue(source, cnt_D, isReverse);
                if (result < 0) {
                    break;
                }
                cnt_D = 0;
            }
        }
        if(result != -1) {
            if (isReverse == false) {
                cout << "[";
                while (!source.empty()) {
                    if (source.size() == 1) {
                        cout << source.front();
                        source.pop_front();
                    } else {
                        cout << source.front() << ",";
                        source.pop_front();
                    }
                }
                cout << "]\n";
            }
            else {
                cout << "[";
                while (!source.empty()) {
                    if (source.size() == 1) {
                        cout << source.back();
                        source.pop_back();
                    } else {
                        cout << source.back() << ",";
                        source.pop_back();
                    }
                }
                cout << "]\n";
            }
        }
    }
}
/*
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

*/