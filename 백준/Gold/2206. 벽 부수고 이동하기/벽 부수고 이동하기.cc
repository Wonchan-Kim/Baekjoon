#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[1001][1001];
int visit[1001][1001][2]; 

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 1}, 0});
    visit[1][1][0] = 1;

    while (!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int wall = q.front().second;
        q.pop();

        if (x == n && y == m)
            return visit[x][y][wall];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m) {
                if (arr[nx][ny] == 0 && visit[nx][ny][wall] == 0) {
                    visit[nx][ny][wall] = visit[x][y][wall] + 1;
                    q.push({{nx, ny}, wall});
                }

                if (arr[nx][ny] == 1 && wall == 0) {
                    visit[nx][ny][wall + 1] = visit[x][y][wall] + 1;
                    q.push({{nx, ny}, wall + 1});
                }
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    cout << bfs() << endl;
    return 0;
}
