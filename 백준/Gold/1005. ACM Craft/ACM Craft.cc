#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        vector<int> time(n); vector<int> prereq(n, 0);
        vector<int> graph[1000];

        for(int i = 0; i < n; i++) {
            cin >> time[i];
        }
        
        for(int i = 0; i < k; i++){
            int start, end;
            cin >> start >> end;
            graph[start-1].push_back(end-1);
            prereq[end-1]++;
        }
        int target;
        cin >> target;

        queue<int> q;
        //start node candidates
        for(int i = 0; i < n; i++){
            if(prereq[i] == 0)
                q.push(i);
        }
        vector<int> result(n);
        while(!q.empty()){
            int start = q.front();
            q.pop();

            for(int next : graph[start]) {
                result[next] = max(result[next], result[start] + time[start]);
                if(--prereq[next] == 0)
                    q.push(next);
            }
        }
        cout << result[target-1] + time[target-1] << endl;
    }
}