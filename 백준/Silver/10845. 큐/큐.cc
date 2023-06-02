#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int num;
    std::cin >> num;

    std::vector<int> ans;
    int frontIdx = 0;
    int backIdx = -1;

    std::vector<int> output;

    while (num--) {
        std::string input;
        std::cin >> input;

        if (input == "push") {
            int value;
            std::cin >> value;
            ans.push_back(value);
            backIdx++;
        }
        else if (input == "pop") {
            if (frontIdx <= backIdx) {
                output.push_back(ans[frontIdx]);
                frontIdx++;
            }
            else {
                output.push_back(-1);
            }
        }
        else if (input == "size") {
            output.push_back(backIdx - frontIdx + 1);
        }
        else if (input == "empty") {
            output.push_back(frontIdx > backIdx ? 1 : 0);
        }
        else if (input == "front") {
            if (frontIdx <= backIdx) {
                output.push_back(ans[frontIdx]);
            }
            else {
                output.push_back(-1);
            }
        }
        else if (input == "back") {
            if (frontIdx <= backIdx) {
                output.push_back(ans[backIdx]);
            }
            else {
                output.push_back(-1);
            }
        }
    }

    for (int value : output) {
        std::cout << value << '\n';
    }

    return 0;
}
