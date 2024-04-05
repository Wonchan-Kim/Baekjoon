#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    while(n--) {
        map<string, int> cnt;
        bool found = false;

        int iter;
        cin >> iter;
        while (iter--) {
            string s1, s2;
            cin >> s1 >> s2;
            for (auto &it: cnt) {
                if (it.first == s2) {
                    it.second++;
                    found = true;
                    break;
                }
            }
            if (!found)
                cnt[s2] = 1;
            found = false;
        }
        int result = 0;
        int sum = 1;
        for(auto &it : cnt){
            sum *= (it.second + 1);
        }
        cout << sum - 1 << endl;
    }
}