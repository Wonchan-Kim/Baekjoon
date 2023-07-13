#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> tempStack;
    vector<int> answer;
    
    for(int number : arr){
        if(tempStack.empty())
            tempStack.push(number);
            
        if(tempStack.top() != number){
            tempStack.push(number);
        }
    }
    while(!tempStack.empty()){
        answer.emplace_back(tempStack.top());
        tempStack.pop();
    }
    reverse(answer.begin(), answer.end());
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    
    return answer;
}