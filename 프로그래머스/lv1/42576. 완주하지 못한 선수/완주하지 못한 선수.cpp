#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    unordered_map<string, int> pc;
    for (const auto& p : participant) {
        pc[p]++;
    }
    for (const auto& c : completion) {
        pc[c]--;
    }

    for (const auto& pair : pc) {
        if (pair.second > 0) {
            return pair.first;
        }
    }

    return "";
}

/*
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    map<string, int> pc;
    for (auto it = participant.begin(); it != participant.end(); it++) {
        if (pc.find(*it) == pc.end())
            pc.insert(make_pair(*it, 1));
        else
            pc.find(*it)->second++;
    }
    for (auto it = completion.begin(); it != completion.end(); it++) {
        if (pc.find(*it) != pc.end()) {
            if (pc.find(*it)->second == 1)
                pc.erase(*it); 
            else
                pc.find(*it)->second--;
        }
    }

    string answer = pc.begin()->first;
    return answer;
}
*/