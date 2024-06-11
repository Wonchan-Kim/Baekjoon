#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    stack<int> S1;
    stack<int> S2;
    stack<int> S3;
    stack<int> S4;
    int N;
    cin >> N;

    for(int i = 0; i < N; i++){
        int val;
        cin >> val;

        bool pushed = false;

        // Try to push val to S1, S2, S3, S4 in that order
        if(S1.empty() || S1.top() < val) {
            S1.push(val);
            pushed = true;
        } else if(S2.empty() || S2.top() < val) {
            S2.push(val);
            pushed = true;
        } else if(S3.empty() || S3.top() < val) {
            S3.push(val);
            pushed = true;
        } else if(S4.empty() || S4.top() < val) {
            S4.push(val);
            pushed = true;
        }

        // If val couldn't be pushed to any stack, print NO and exit
        if(!pushed) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
