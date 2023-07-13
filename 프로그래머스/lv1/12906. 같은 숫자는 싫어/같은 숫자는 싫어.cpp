#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> arr) 
{
    queue<int> tempQueue;
    vector<int> answer;
    
    for(int number : arr){
        if(tempQueue.empty())
            tempQueue.push(number);
            
        if(tempQueue.back() != number){
            tempQueue.push(number);
        }
    }
    while(!tempQueue.empty()){
        answer.emplace_back(tempQueue.front());
        tempQueue.pop();
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    
    return answer;
}