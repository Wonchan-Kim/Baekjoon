/*
A1...AN

Backtracking


*/
#include <iostream>
#include <algorithm>

using namespace::std;
int n;
int max_ = -1000000001;
int min_ = 1000000001;
int operands[11];
int operators[11];
void backtracking(int result, int index){
    if(index == n){
        if(result > max_)
            max_ = result;
        if(result < min_)
            min_ = result;
        return;
    }
    for(int i = 0; i < 4; i++){
        if(operators[i] > 0){
            operators[i]--;
            if(i == 0){
                backtracking(result + operands[index], index +1);
            }
            else if(i == 1)
                backtracking(result - operands[index], index + 1);
            else if(i == 2)
                backtracking(result * operands[index], index + 1);
            else if(i == 3)
                backtracking(result / operands[index], index + 1);
            operators[i]++;
        }
    }
    return;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> operands[i];
    }
    for(int i = 0; i < 4; i++)
        cin >> operators[i];
    backtracking(operands[0],1);

    cout << max_ << endl << min_ << endl;
}