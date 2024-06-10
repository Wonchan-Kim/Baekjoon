#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    long long answer = 0;

    vector<pair<int,int>> jewel(n);
    for(int i = 0; i < n; i++){
        int M, V;
        cin >> M >> V;
        jewel[i] = {M, V};
    }
    
    vector<int> bag(k);
    for(int i = 0; i < k; i++) {
        cin >> bag[i];
    }
    
    sort(jewel.begin(), jewel.end());
    sort(bag.begin(), bag.end());

    priority_queue<int> pq;
    int j = 0;

    for(int i = 0; i < k; i++){
        while (j < n && jewel[j].first <= bag[i]) {
            pq.push(jewel[j].second);
            j++;
        }

        if(!pq.empty()){
            answer += pq.top();
            pq.pop();
        }
    }
    cout << answer << endl;
    return 0;
}
