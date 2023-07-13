#include <string>
#include <vector>
#include <queue>


using namespace std;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;

    for(int i = 0; i < bridge_length; i++){
        bridge.push(0);
    }
    int bridge_sum = 0;
    int next_num = 0;

    while (next_num < truck_weights.size()) {
        bridge_sum -= bridge.front();
        bridge.pop();
        if (bridge_sum + truck_weights[next_num] <= weight) {
            bridge.push(truck_weights[next_num]);
            bridge_sum += truck_weights[next_num];
            next_num++;
            answer++;
        }
        else{
            bridge.push(0);
            answer++;
        }
    }

    answer += bridge_length;

    return answer;
}
