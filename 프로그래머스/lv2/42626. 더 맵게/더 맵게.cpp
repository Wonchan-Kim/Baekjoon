#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> pq;
    int q_top;
    int mix;
    vector<int>::iterator it;
    
    for(it = scoville.begin(); it != scoville.end(); it++){
        *it *= -1;
        pq.push(*it);
    }
    
    while(pq.size() > 1 && pq.top() > -K){
        q_top = pq.top();
        pq.pop();
        mix = pq.top();
        pq.pop();
        q_top += mix * 2;
        pq.push(q_top);
        answer++;
    }
    
    return pq.top() <= -K ? answer : -1;
}
/*
the values will be sorted into descending order.
[1, 2, 3, 9, 10, 12]	7	2

in the following example, 
1
2
3
9
10
12

this is how queue will be sorted.

always check whether the top element of the queue is smaller or larger than the K.
if smaller, pop two elements, and mix and put it in the queue again. 
*/