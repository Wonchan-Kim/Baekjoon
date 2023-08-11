#include <iostream>
#include <vector>
#include <cstring>
#define red 2
#define blue 3
using namespace::std;

vector<vector<int>> graph;
vector<int> is_visited;
void input(int v, int e)
{
    graph.assign(v+1, vector<int>(0,0));
    is_visited.assign(v+1, 0);
    
    for(int i = 0; i < e; i++)
    {
        int s, a;
        cin >> s >> a;
        graph[s].emplace_back(a);
        graph[a].emplace_back(s);
    }
}
void dfs(int start)
{
    if(!is_visited[start])
        is_visited[start] = red;
    for(int i = 0; i < graph[start].size(); i++)
    {
        int next = graph[start][i];
        if(!is_visited[next])
        {
            if(is_visited[start] == red)
                is_visited[next] = blue;
            else if(is_visited[start] == blue)
                is_visited[next] = red;
        
            dfs(next);
        }
    }
}
int solve(int v)
{
    for(int i = 1; i <= v; i++)
    {
        for(int j = 0; j < graph[i].size(); j++)
        {
            int next = graph[i][j];
            if(is_visited[i] == is_visited[next])
                return 0;
        }
    }
    return 1;
}
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int v , e;
        cin >> v >> e;
        input(v,e);
        for(int k = 1; k < v+1; k++)
        {
            dfs(k);
        }
        if(solve(v))
            cout << "YES\n";
        else
            cout << "NO\n";
        
        for(int i = 1; i < v+1; i++)
        {
            graph[i].clear();        
            is_visited[i] = 0;
        }
    }
}