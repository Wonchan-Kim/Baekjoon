#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}
 
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> temp;
    //string으로 바꾼후 벡터에 집어넣는다.
    for (auto num : numbers)
        temp.push_back(to_string(num));
    //더할때 오름차순으로 정렬한다.
    sort(temp.begin(), temp.end(), cmp);
    //처음 숫자가 0이라면 0을 반환
    if (temp.at(0) == "0")        return "0";
    //처음부터 끝까지 문자열 합치고 리턴
    for (auto num : temp)
        answer += num;
    return answer;
}

/*
#include <string>
#include <vector>

using namespace std;

void backtracking(int length, string& max, vector<int>& numbers, vector<bool>& visited, string& temp);

string solution(vector<int> numbers) {
    string answer = "";
    string max = "0";
    vector<bool> visited(numbers.size(), false);
    string temp = "";
    backtracking(0, max, numbers, visited, temp);

    answer = max;
    return answer;
}

void backtracking(int length, string& max, vector<int>& numbers, vector<bool>& visited, string& temp) {
    if (length == numbers.size()) {
        max = (max > temp) ? max : temp;
        return;
    }

    int first_d_m = max[0] - '0';
    int first_d_t = (temp.empty()) ? 0 : temp[0] - '0';

    if (first_d_m > first_d_t)
        return;

    for (int i = 0; i < numbers.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            temp += to_string(numbers[i]);
            int added_length = to_string(numbers[i]).length();
            backtracking(length + 1, max, numbers, visited, temp);
            temp.erase(temp.length() - added_length, added_length);
            visited[i] = false;
        }
    }
}

*/