#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int N;
vector<int> store;
bool checked[14] = {false};
int arr[14];
void backtracking(int len){
    if(len == 6){
        for(int i = 0; i < len; i++){
            cout << store[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i < N; i++){
        if(checked[i] == false && store.back() < arr[i]){
            checked[i] = true;
            store.push_back(arr[i]);
            backtracking(len+1);
            store.pop_back();
            checked[i] = false;
        }
    }
}

int main(){
    while(1){
        cin >> N;
        if(N == 0)
            return 0;
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        sort(arr, arr+N);
        
        for(int i = 0; i < N; i++){
            store.push_back(arr[i]);
            backtracking(1);
            store.pop_back();
        }
        cout << '\n';
    }
}