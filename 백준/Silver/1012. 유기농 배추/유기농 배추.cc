#include <iostream>
#include <vector>

using namespace std;

bool check_valid(vector<vector<bool>> &map, int i, int j) {
    int row = map.size();
    int col = map[0].size();

    if (i < 0 || i >= row || j < 0 || j >= col)
        return false;
    return true;
}

void dfs(vector<vector<bool>> &map, vector<vector<bool>> &visited, int i, int j) {
    visited[i][j] = true;

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    for (int a = 0; a < 4; a++) {
        int new_i = i + dx[a];
        int new_j = j + dy[a];

        if (check_valid(map, new_i, new_j) && !visited[new_i][new_j] && map[new_i][new_j]) {
            dfs(map, visited, new_i, new_j);
        }
    }
}

int find_veg(vector<vector<bool>> &map, vector<vector<bool>> &visited) {
    int cnt = 0;
    int rows = map.size();
    int cols = map[0].size();

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!visited[i][j] && map[i][j]) {
                dfs(map, visited, i, j);
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int row, col, veg;
        cin >> row >> col >> veg;

        vector<vector<bool>> map(row, vector<bool>(col, false));
        vector<vector<bool>> visited(row, vector<bool>(col, false));

        while (veg--) {
            int x, y;
            cin >> x >> y;
            map[x][y] = true;
        }
        cout << find_veg(map, visited) << endl;
    }

    return 0;
}
