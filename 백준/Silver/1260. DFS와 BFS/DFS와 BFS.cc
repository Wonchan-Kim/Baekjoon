#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <memory.h>
using namespace std;
vector<int> result;
void dfs(const vector<vector<int>>& graph, vector<bool>& visited, const int& search){
    visited[search] = true;
    result.push_back(search);

    for(int i = 0; i < graph[search].size(); i++){
        if(!visited[graph[search][i]]){
            dfs(graph, visited, graph[search][i]);
        }
    }
}

void bfs(const vector<vector<int>>& graph, vector<bool>& visited, const int& search){
    queue<int> q;
    q.push(search);
    visited[search] = true;
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        result.push_back(temp);

        for(int i = 0; i < graph[temp].size(); i++){
            if(!visited[graph[temp][i]]){
                q.push(graph[temp][i]);
                visited[graph[temp][i]] = true;
            }
        }
    }
}

int main() {

    int n, m, v;
    cin >> n >> m >> v; //n is edge, m is vertex, v is to search
    vector<bool> visited(n+1);
    vector<vector<int>> graph(n+1);
    while(m--) {
        int start, end;
        cin >> start >> end;
        graph[start].push_back(end);
        graph[end].push_back(start);
        //non-directed graph
    }
    for(int i = 1; i <= n; i++){
        sort(graph[i].begin(), graph[i].end());
    }
    dfs(graph, visited, v);
    std::fill(visited.begin(), visited.end(), false); // Reset visited for DFS or any further processing
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ' ';
    }
    cout << endl;
    result.clear();
    bfs(graph, visited, v);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << ' ';
    }
    cout << endl;
}