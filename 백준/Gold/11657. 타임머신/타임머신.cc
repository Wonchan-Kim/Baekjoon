#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const long long int INF = LLONG_MAX;
long long int N, M;
vector<pair<pair<long long int, long long int>, long long int>> Edge;
vector<long long int> Dist;

void Bellman_Ford() {
    Dist[1] = 0;
    for (long long int i = 1; i <= N - 1; i++) {
        for (long long int j = 0; j < Edge.size(); j++) {
            long long int From = Edge[j].first.first;
            long long int To = Edge[j].first.second;
            long long int Cost = Edge[j].second;

            if (Dist[From] == INF) continue;
            if (Dist[To] > Dist[From] + Cost) {
                Dist[To] = Dist[From] + Cost;
            }
        }
    }

    for (long long int i = 0; i < Edge.size(); i++) {
        long long int From = Edge[i].first.first;
        long long int To = Edge[i].first.second;
        long long int Cost = Edge[i].second;

        if (Dist[From] == INF) continue;
        if (Dist[To] > Dist[From] + Cost) {
            cout << "-1" << endl;
            return;
        }
    }

    for (long long int i = 2; i <= N; i++) {
        if (Dist[i] == INF) {
            cout << "-1" << endl;
        } else {
            cout << Dist[i] << endl;
        }
    }
}

int main() {
    cin >> N >> M;
    Edge.resize(M);
    Dist.resize(N + 1, INF);

    for (long long int i = 0; i < M; i++) {
        long long int from, to, cost;
        cin >> from >> to >> cost;
        Edge[i] = {{from, to}, cost};
    }

    Bellman_Ford();
    return 0;
}
