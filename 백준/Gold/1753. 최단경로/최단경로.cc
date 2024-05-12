#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

vector<vector<pair<int,int>>> graph;
vector<int> dis_vec;

void dijkstra(int start) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min heap
    pq.push({0, start}); // Distance, Vertex
    dis_vec[start] = 0;

    while (!pq.empty()) {
        int current_dist = pq.top().first;
        int current_node = pq.top().second;
        pq.pop();

        // Iterate all the adjacent nodes
        for (const auto& edge : graph[current_node]) {
            int next_node = edge.first;
            int edge_weight = edge.second;

            if (current_dist + edge_weight < dis_vec[next_node]) {
                dis_vec[next_node] = current_dist + edge_weight;
                pq.push({dis_vec[next_node], next_node});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int V, E;
    cin >> V >> E;
    int start;
    cin >> start;

    graph.resize(V + 1); // Resize to V + 1
    dis_vec.resize(V + 1, INT_MAX); // Initialize distances

    while (E--) {
        int from, to, dist;
        cin >> from >> to >> dist;
        graph[from].push_back({to, dist}); // Add edge to adjacency list
    }

    dijkstra(start);

    for (int i = 1; i <= V; i++) {
        if (dis_vec[i] == INT_MAX)
            cout << "INF" << '\n';
        else
            cout << dis_vec[i] << '\n';
    }

    return 0;
}
