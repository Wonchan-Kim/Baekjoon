#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    priority_queue<int> pq;
    int N;
    cin >> N;
    while(N--){
        int input;
        cin >> input;
        if(input){
            pq.push(input);
        }
        else {
            if(pq.empty()){
                cout << 0 << "\n";
            }
            else {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
    }
}