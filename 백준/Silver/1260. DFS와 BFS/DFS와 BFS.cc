#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace::std;

int v, e; // 정점 , 간선
vector<vector<int>> graph;
vector<bool> isVisited;

void input(int v, int e)
{
    
    graph.assign(v + 1, vector<int> (0,0)); //인덱스 0에 0을 넣고 정점 개수 만큼 복사
    isVisited.assign(v + 1, false);
    
    for(int i = 0; i < e; i++)
    {
        int s, e;
        cin >> s >> e;
        graph[s].emplace_back(e);
        graph[e].emplace_back(s);
    }
    for(int i = 0; i < v+ 1; i++)
        sort(graph[i].begin(), graph[i].end());
}

void BFS(int cur)
{
    queue <int> q;
    q.push(cur);
    isVisited[cur] = true;
    
    
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << ' ';
        for(int i = 0; i < graph[x].size(); i++)
        {
            int y = graph[x][i];
            if(!isVisited[y]){
                q.push(y);
                isVisited[y] = true;
                
            }
        }
    }
    
}

void DFS(int cur)
{
    isVisited[cur] = true;
    cout<< cur << ' ';
    
    for(int i = 0; i < graph[cur].size(); i++)
    {
        int next = graph[cur][i];
        if(!isVisited[next])
            DFS(next);
    }
}

int main()
{
    int v , e;
    cin >> v >> e;
    int i;
    cin >> i;
    input(v,e);
    
    DFS(i);
    cout << '\n';
  
    
    for(int itr = 0; itr <= v; itr++)
        isVisited[itr] = false;
    
      BFS(i);
    
}