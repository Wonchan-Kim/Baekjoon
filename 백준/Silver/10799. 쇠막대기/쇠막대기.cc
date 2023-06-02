/*
각 막대기당 레이저 개수 + 1 이 얻을 수 있는 조각 개수
즉 ()의 개수 + 1 이 각 막대기마다 얻어지는 조각의 개수이다.
(((())))
solution:
stack++ if '(' : get the number of sticks 
s[i-1] s[i] () : means the razer, +number ot sticks
stack-- if ')' : reduce the numer of sticks, add one into result
*/

#include <iostream>
#include <stack>
#define MAX 100001

using namespace::std;

int main()
{
    string s;
    cin >> s;
    stack<char> stick;
    int ans = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == '(')
            stick.push(s[i]);
        else if(s[i] == ')')
        {
            stick.pop();
            if(s[i-1] == '(')
            {  
                ans += stick.size();
            }
            else ans++;
        }
    }
    cout << ans;
}