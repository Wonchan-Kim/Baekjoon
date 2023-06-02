/*
Queue is absract data structure in which a collection of entities that are maintained 
in a sequence and can be modified by the addition of entities at one end of the sequence
and the removal of entities from the other end of the sequence.

End of the sequence at which elements are added is called 'Back', 'Tail', 'Rear',
and the end at which elements are removed is called the 'Head' or 'Front' of the queue.

Operations of queue make it a FIFO structure, first-in-first-out.

ADT:
    push
    pop
    size
    empty
    front
    back
*/
#include <iostream>
#include <string>
#include <queue>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    int num;
    std::cin >> num;
    std::cin.ignore();  // Ignore the newline character after reading 'num'

    std::queue<int> ans;

    while (num--) {
        std::string input;
        std::cin >> input;

        if (input == "push") {
            int i;
            std::cin >> i;
            ans.push(i);
        }
        else if (input == "pop") {
            if (!ans.empty()) {
                int x = ans.front();
                ans.pop();
                std::cout << x << '\n';
            }
            else {
                std::cout << -1 << '\n';
            }
        }
        else if (input == "size") {
            std::cout << ans.size() << '\n';
        }
        else if (input == "empty") {
            std::cout << (ans.empty() ? 1 : 0) << '\n';
        }
        else if (input == "front") {
            if (!ans.empty()) {
                std::cout << ans.front() << '\n';
            }
            else {
                std::cout << -1 << '\n';
            }
        }
        else if (input == "back") {
            if (!ans.empty()) {
                std::cout << ans.back() << '\n';
            }
            else {
                std::cout << -1 << '\n';
            }
        }
    }

    return 0;
}
