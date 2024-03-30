#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string str;
    getline(cin, str);
    
    int result = 0;
    string tmp = "";
    bool minus = false;

    for (int i = 0; i <= str.length(); i++) {
        if (str[i] == '+' || str[i] == '-' || i == str.length()) { 
            if (minus) {
                result -= stoi(tmp);
                tmp = ""; //임시 문자열 초기화
            }
            else {
                result += stoi(tmp);
                tmp = ""; 
            }
        }
        else {
            tmp += str[i];
        }
        
        if (str[i] == '-') {
            minus = true;
        }
    }
    cout << result << '\n';
}