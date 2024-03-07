#include <iostream>
#include <queue>

using namespace std;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    priority_queue<int> queue;
    int rep;
    cin >> rep;
    while(rep--){
        int x;
        cin >> x;
        if(x != 0)
            queue.push(-x);
        else{
            if(queue.size() == 0) {
                cout << 0 << '\n';
                continue;
            }
            int top = queue.top();
            cout << -top << '\n';
            queue.pop();
        }
    }
}