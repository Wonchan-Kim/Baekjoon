#include <string>
#include <iostream>
//abcdefghijklm  nopqrxtuvwxyz

using namespace::std;

int main(){
    string input;
    getline(cin, input);

    for(int i = 0; i < input.size(); i++){
        if(input[i] >= 'a' && input[i] <= 'm')
            input[i] += 13;
        else if(input[i] >= 'n' && input[i] <= 'z')
            input[i] -= 13;
        else if(input[i] >= 'A' && input[i] <= 'M')
            input[i] += 13;
        else if(input[i] >='N' && input[i] <= 'Z')
            input[i] -= 13;
    }

    cout << input << endl;
}