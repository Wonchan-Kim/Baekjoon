#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer; 
    int f_index = -1;
    int l_index = -1;
    int range = -1;
    for (const auto &it : commands) {
        f_index = it[0] - 1;
        l_index = it[1];
        range = it[2] - 1;
        cout << f_index << l_index << range << endl;
        cout << array[f_index] << array[l_index] << endl;
        vector<int> temp(array.begin() + f_index, array.begin() + l_index);
        sort(temp.begin(), temp.end());
        answer.emplace_back(temp[range]);
    }
    return answer;
}
