#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    int temp = x + y;
    set<string> ans;
    set<string> dict;
    while(temp--){
        string s;
        cin >> s;
        int size = dict.size();
        dict.insert(s);
        if(dict.size() == size)
            ans.insert(s);
    }
    cout << ans.size() << endl;
    for(auto& it : ans){
        cout << it << endl;
    }
}