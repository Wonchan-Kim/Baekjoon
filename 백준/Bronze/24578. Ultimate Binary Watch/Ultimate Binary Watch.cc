#include <bits/stdc++.h>
using namespace std;
void create(int col, char c, vector<vector<char>>& grid) {
    int x = c - '0'; // Convert char to int
    string s;
    char digits[] = {'0', '1'};
    while (s.length() < 4) {
        s = digits[x % 2] + s;
        x = x / 2;
    }
    for (int i = 0; i < 4; i++) {
        if (s[i] == '0') 
            grid[i][col] = '.';
        else
            grid[i][col] = '*';

    }
}

int main() {
    string s;
    cin >> s;
    vector<vector<char>> grid(4, vector<char>(4));
    for (int i = 0; i < 4; i++)
        create(i, s[i], grid);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)  {
            cout << grid[i][j];
            if (j == 1)
                cout << "   ";
            else if (j < 3)
                cout << " ";
        }

        cout << endl;
    }

}