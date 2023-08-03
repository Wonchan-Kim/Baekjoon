#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(), citations.end(), greater<int>());
    
    if(citations[0] == 0)
        return 0;
    for(int i = 0; i < citations.size(); i++){
        if(citations[i] > i)
            answer++;
        else
            break;
    }
    return answer;
}

/*
정렬된 상태에서
i 번째 인덱스에서 citations[i]가 i보다 크면 된다.

0 1 3 5 6

6 5 3 1 0

최댓값 기준 정렬후 index값 비교
*/

