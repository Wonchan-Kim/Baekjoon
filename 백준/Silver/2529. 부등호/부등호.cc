#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int N;
vector<int> store;
char inequality[10];
bool visited[10] = {false};
string min_str;
string max_str;
string compare_with;
stringstream ss;
int checkIfComparison(int lastCharofVec, int givench, char ineuqalityop){
    if(ineuqalityop == '>' && lastCharofVec > givench){
        return 1;
    }
    else if(ineuqalityop == '<' && lastCharofVec < givench){
        return 1;
    }
    return 0;
}

std::string vectorToString(const std::vector<int>& vec) {
    std::stringstream ss;
    for (const int& num : vec) {
        ss << num;
    }
    return ss.str();
}


void backtracking(int len, int index){//NOTE: index is saving the index of inequality array
    if(len == N+1){
        compare_with = vectorToString(store);
        if(compare_with > max_str){
            max_str = compare_with;
        }
        if(min_str > compare_with){
            min_str = compare_with;
        }
        return;
    }
    for(int i = 0; i < 10; i++){
        char comparison = inequality[index];

        if(visited[i])
            continue;
        if(checkIfComparison(store.back(), i, comparison)){
            visited[i] = true;
            store.push_back(i);
            backtracking(len + 1, index + 1);
            store.pop_back();
            visited[i] = false;
        }
    }
}
int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        min_str += '9';
        max_str += '0';
    }
    for(int i = 0; i < N; i++){
        cin >> inequality[i];
    }
    for(int i = 0; i < 10; i++){
        visited[i] = true;
        store.push_back(i);
        backtracking(1, 0);
        visited[i] = false;
        store.pop_back();
    }
    cout << max_str << '\n' << min_str << '\n';
}