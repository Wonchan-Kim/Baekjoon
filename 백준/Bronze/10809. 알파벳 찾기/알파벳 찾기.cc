#include <string>
#include <iostream>
#include <vector>

using namespace::std;

int main(){
    string s1;
    vector<int> ans(26,-1);
    cin >> s1;
    for(int i= 0; i < s1.size(); i++){
        if(ans[s1[i] - 'a'] == -1)
                ans[s1[i] - 'a'] = i;
    }
    for(int i = 0 ; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
    cout << endl;
}