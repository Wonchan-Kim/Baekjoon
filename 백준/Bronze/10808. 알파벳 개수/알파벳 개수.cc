#include <iostream>

using namespace std;

int alph[26];

int    main(void)
{
    string s;
    cin >> s;
    for (auto c : s)
        alph[c - 'a']++;
    for (auto n : alph)
        cout << n << ' ';
}