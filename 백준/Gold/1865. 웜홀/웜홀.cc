#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int INF = 987654321;
vector<pair<pair<int, int>, int>> edges;
vector<int> dist;

bool detect_negative_cycle(int n) {
    dist[1] = 0;
    for (int i = 0; i < n - 1; ++i) {
        for (auto& edge : edges) {
            int u = edge.first.first;
            int v = edge.first.second;
            int weight = edge.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (auto& edge : edges) {
        int u = edge.first.first;
        int v = edge.first.second;
        int weight = edge.second;

        if (dist[u] + weight < dist[v]) {
            return true;  // Negative cycle found
        }
    }

    return false;  // No negative cycle found
}

int main() {
    int TC;
    cin >> TC;

    while (TC--) {
        int n, m, w;
        cin >> n >> m >> w;

        edges.clear();
        dist.assign(n + 1, INF);

        for (int i = 0; i < m; ++i) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({{s, e}, t});
            edges.push_back({{e, s}, t});

        }

        for (int i = 0; i < w; ++i) {
            int s, e, t;
            cin >> s >> e >> t;
            edges.push_back({{s, e}, -t});
        }

        cout << (detect_negative_cycle(n) ? "YES" : "NO") << endl;
    }

    return 0;
}
