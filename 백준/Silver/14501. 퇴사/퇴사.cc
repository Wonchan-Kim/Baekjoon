#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int res = 0;
int n = 0;
int a =  0;
int b = 0;
vector<pair<int,int>> v;
vector<int> ans(16,0);
int day1[100];
void dfs(int day, int money){
    res = max(res, money);
    if(day >= n+1) return;
    if(day + v[day].first <= n + 1)
        dfs(day + v[day].first, money + v[day].second);
    if(day + 1 <= n ) dfs(day + 1, money);
}

int main(){
    v.push_back(make_pair(0,0));
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a >> b;
        v.push_back(make_pair(a,b));
    }
    dfs(1,0);
    cout << res << endl;
}