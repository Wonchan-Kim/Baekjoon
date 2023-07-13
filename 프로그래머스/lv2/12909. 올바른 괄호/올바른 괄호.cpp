#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    stack<char> fpStack;
    bool answer = true;

    for(int i = 0; i < s.length(); i++){
        if(s[i] == '('){
            fpStack.push('(');
        }
        else{
            if(fpStack.empty())
                return false;
            fpStack.pop();       
        }
    }
    if(!fpStack.empty())
            answer = false;
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.

    return answer;
}
// ) 나오면 ( 을 담고 있는 스택에서 pop.  