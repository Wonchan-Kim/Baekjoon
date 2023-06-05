#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace::std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string temp;
    string s;
    cin >> s;
    vector<string> _substr;
    for(int i = 0; i < s.length(); i++)
    {
        temp = s.substr(i, s.length());
        _substr.push_back(temp);
    }
    sort(_substr.begin(), _substr.end());
    for(int i = 0; i < _substr.size(); i++)
        cout << _substr[i] << '\n';
    return 0;
}