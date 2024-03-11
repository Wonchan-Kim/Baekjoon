#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int bfs(int start){
    int cnt = 0;
    queue<int> bfs;
    visited[start] = true;
    bfs.push(start);

    while(!bfs.empty()){
        int x = bfs.front();
        bfs.pop();
        visited[x] = true;

        for(int i = 0; i < graph[x].size(); i++){
            if(!visited[graph[x][i]]){
                visited[graph[x][i]] = true;
                bfs.push(graph[x][i]);
                cnt++;

            }
        }
    }
    return cnt;
}

int main() {
    int n;
    cin >> n;
    graph.resize(n+1);
    int line;
    cin >> line;
    for(int i = 0; i < line; i++){
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
    }
    visited.resize(n+1);
    cout << bfs(1) << endl;
}