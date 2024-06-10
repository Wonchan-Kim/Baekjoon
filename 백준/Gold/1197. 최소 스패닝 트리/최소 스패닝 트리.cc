#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int v,e;
    cin >> v >> e;
    vector<pair<int,int>> graph[10001];
    vector<bool> visited(10001);

    for(int i = 0; i < e; i++) {
        int start, end, dist;
        cin >> start >> end >> dist;

        graph[start].push_back({end,dist});
        graph[end].push_back({start,dist});
    }
    int answer = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0, 1}); //push the first node

    while(!pq.empty()){
        int cur_node = pq.top().second;
        int dist = pq.top().first;
        pq.pop();
        if(visited[cur_node]){
            continue;
        }
        
        visited[cur_node] = true;
        answer += dist;

        for(auto& i : graph[cur_node]){
            int end = i.first;
            int distance = i.second;
            if(!visited[end]) {
         
                pq.push({distance, end});
            }
        }
    }
    cout << answer << endl;
}