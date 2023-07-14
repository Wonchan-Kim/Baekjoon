#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> temp_container;
    queue<int> speeds_container;
    int size = progresses.size();
    for (int i = 0; i < size; i++) {
        temp_container.push(progresses[i]);
        speeds_container.push(speeds[i]);
    }
    
    int day = 0;
    int work_load = 0;
    
    while (!temp_container.empty()) {
        int progress = temp_container.front() + speeds_container.front() * day;
        
        if (progress >= 100) {
            temp_container.pop();
            speeds_container.pop();
            work_load++;
        }
        else {
            if (work_load > 0) {
                answer.emplace_back(work_load);
                work_load = 0;
            }
            
            day++;
        }
    }
    
    if (work_load > 0) {
        answer.emplace_back(work_load);
    }
    
    return answer;
}
