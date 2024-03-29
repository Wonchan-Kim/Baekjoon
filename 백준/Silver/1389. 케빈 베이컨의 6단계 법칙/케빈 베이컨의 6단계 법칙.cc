#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX_N = 100;
vector<int> adj[MAX_N + 1];
int N, M;

int bfs(int start) {
    queue<int> q;
    vector<bool> visited(N + 1, false);
    vector<int> depth(N + 1, 0);

    q.push(start);
    visited[start] = true;

    int totalFamiliarity = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
                depth[neighbor] = depth[node] + 1;
                totalFamiliarity += depth[neighbor];
            }
        }
    }

    return totalFamiliarity;
}

int main() {
    cin >> N >> M;

    for (int i = 0; i <= N; i++) {
        adj[i].clear();
    }

    while (M--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int minFamiliarity = MAX_N * MAX_N;
    int answer = 0;

    for (int i = 1; i <= N; i++) {
        int totalFamiliarity = bfs(i);

        if (totalFamiliarity < minFamiliarity) {
            minFamiliarity = totalFamiliarity;
            answer = i;
        }
    }

    cout << answer << endl;

    return 0;
}
