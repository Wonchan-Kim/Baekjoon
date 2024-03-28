#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    map<int, int> m;
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int pos;
        cin >> pos;
        arr.push_back(pos);
        m.insert({pos, 0});
    }
    int cur = 0;
    for(auto& i : m){
        i.second = cur;
        cur++;
    }
    for(auto i : arr){
        cout << m[i] << " ";
    }
    return 0;
}