#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::cout.tie(0);
    int size, problems;
    cin >> size >> problems;
    unordered_map<string, int> dictionary;
    unordered_map<int, string> reverse_dict;
    for(int i = 0; i < size; i++){
        string s;
        cin >> s;
        dictionary[s] = i + 1;
        reverse_dict[i+1] = s;
    }
    while(problems--){
        string s;
        cin >> s;
        if(dictionary.find(s) != dictionary.end()) {
            cout << dictionary[s] << '\n';
        }
        else {
            int number = stoi(s);
            cout << reverse_dict[number] << '\n';
        }
    }
    return 0;
}
