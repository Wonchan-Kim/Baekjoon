#include <iostream>
#include <queue>
#include <string>
using namespace std;

string bfs(int cur, int target){
    bool visited[10000] = {false};
    queue<pair<int,string>> q;
    q.push({cur, ""});
    while(!q.empty()){
        int num = q.front().first;
        string stage = q.front().second;
        q.pop();
        if(num == target)
            return stage;
        int temp = num * 2 > 9999 ? num * 2 % 10000 : num * 2;
        if(!visited[temp]){
            visited[temp] = true;
            q.push({temp, stage + "D"});
        }

        temp = num - 1 < 0 ? 9999 : num -1;
        if(!visited[temp]){
            visited[temp] = true;
            q.push({temp, stage + "S"});
        }

        int mod = num % 1000;
        int res = num / 1000;
        temp = mod * 10 + res;
        if(!visited[temp]){
            visited[temp] = true;
            q.push({temp, stage + "L"});
        }

        mod = num / 10;
        res = num % 10;
        temp = res * 1000 + mod;
        if(!visited[temp]){
            visited[temp] = true;
            q.push({temp, stage + "R"});
        }
    }
    return "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
    int tc;
    cin >> tc;
    while(tc--){
        int cur, target;
        cin >> cur >> target;
        cout << bfs(cur, target) << '\n';
    }
}