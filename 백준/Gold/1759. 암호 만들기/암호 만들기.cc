#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<char> store;
bool visited[16] = {false};
char arr[16];

bool check_vowel(char c){
    char vowel[5] = {'a', 'e', 'i', 'o', 'u'};
    for(int i = 0; i < 5; i++){
        if(c == vowel[i])
            return true;
    }
    return false;
}

void backtracking(int len){
    if(len == N){
        int vowelCount = 0;
        int notvowel = 0;
        for(int i = 0; i < len; i++){
            if(check_vowel(store[i]))
                vowelCount++;
            else
                notvowel++;
        }
        if(vowelCount >= 1 && notvowel >= 2){
            for(int i = 0; i < len; i++){
                cout << store[i];
            }
            cout << '\n';
        }
        return;
    }
    for(int i = 0; i < M; i++){
        if(visited[i] == false && (store.empty() || store.back() < arr[i])){
            visited[i] = true;
            store.push_back(arr[i]);
            backtracking(len+1);
            visited[i] = false;
            store.pop_back();
        }
    }
}

int main(){
    cin >> N >> M;
    for(int i = 0; i < M; i++){
        cin >> arr[i];
    }
    sort(arr, arr + M);
    backtracking(0);
    return 0;
}
