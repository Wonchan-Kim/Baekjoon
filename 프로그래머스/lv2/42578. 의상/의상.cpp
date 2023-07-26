#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    unordered_map<string, int> mp;
    for(const auto& it : clothes){
        mp[it[1]]++;
    }
    for(const auto& it : mp){
        answer *= (it.second + 1);
    }
    
    return answer - 1;
}