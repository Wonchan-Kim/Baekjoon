#include <string>
#include <vector>
#include <iostream>

using namespace::std;

int main(){
    
        string input;
        while(getline(cin, input)){
        int small = 0;
        int big = 0;
        int num = 0;
        int space = 0;
        for(long unsigned int i = 0; i < input.size(); i++){
            if(input[i] >= 'a' && input[i] <= 'z')
                small++;
            else if(input[i] >= 'A' && input[i] <= 'Z')
                big++;
            else if(input[i] == ' ')
                space++;
            else if(input[i] >= '0' && input[i] <= '9')
                num++;
        }
        cout << small << ' ' << big << ' ' << num << ' ' << space << endl;
    }
}