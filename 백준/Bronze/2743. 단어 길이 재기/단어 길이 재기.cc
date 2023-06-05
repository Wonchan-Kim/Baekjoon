#include <string>
#include <iostream>
using namespace::std;

int main(){
    string word;
    cin >> word;
    int len = 0;
    int i = 0;
    while(word[i]){
        len++;
        i++;
    }
    cout << len << endl;
}