#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check[10] = {false};
vector<int> store;
int arr[10];
int N;
void backtracking(int len){
    if(len == N){
        for(int i = 0; i < len; i++){
            cout << store[i] << ' ';
        }
        cout << '\n';
    }

    for(int i = 0; i < N; i++){
        if(check[i] == false){
            check[i] = true;
            store.push_back(arr[i]);
            backtracking(len+1);
            store.pop_back();
            check[i] = false;
        }
    }
}
int main(){
    cin >> N;
    for(int i = 0 ; i < N; i++){
        arr[i] = i + 1;
    }
    backtracking(0);
}