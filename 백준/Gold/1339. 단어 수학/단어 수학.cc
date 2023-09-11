/* 민식 단어 수학 문제 
N개의 단아문제, 알파벳 대문자 0-9 하나로 바꿔서 n개의 수를 합하는 문제

모든 단어에 포함되어 있는 알파벳은 최대 10개이고 수의 최대 길이는 8이다
*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int priority[27] = {0};

bool cmp(int &a, int &b){
    return a > b;
}

int main(){
    int n_input;
    cin >> n_input;

    while (n_input)
    {
        string a;
        cin >> a;
        int pow = 1;
        for(int j = a.length() - 1; j >= 0; j--){
            priority[a[j] - 'A'] += pow;
            pow *= 10;
        }
        n_input--;
    }

    sort(priority, priority+26, cmp);
    
    int num = 9;
    int answer = 0;
    for(int i = 0; i < 26; i++){
        if (priority[i] == 0)
            continue;
        answer += priority[i] * num--;
    }
    cout << answer << endl;

    return 0;
}
