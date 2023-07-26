#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool solution(vector<string> phone_book) {
    if(phone_book.size() == 1)
        return true;
    sort(phone_book.begin(), phone_book.end());
    for(int it = 0; it < phone_book.size()-1; it++){
        if(phone_book[it] == phone_book[it + 1].substr(0, phone_book[it].length())) 
            return false;
    }
    return true;
}