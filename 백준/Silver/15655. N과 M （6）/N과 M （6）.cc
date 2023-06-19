#include <iostream>
#include <vector>
#include <algorithm>

/*
TODO: 중복되는 수열 x, 오름차순
CHECKLIST:  1. 백트래킹 조건을 만족하는가? 2. 이미 지나간 수에 대한 처리가 되었는가? 3.출력을 마친뒤 종료 하였는가?

*/
using namespace::std;
int M, N;
vector<int> store;
bool check[10];
int arr[9];

void backtracking(int len){
    if(len == N){
        for(int i = 0; i < N; i++){
            cout << store[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i = 1; i < M; i++){
        if(check[i] == false && store.back() < arr[i]){
            check[i] = true;
            store.push_back(arr[i]);
            backtracking(len+1);
            store.pop_back();
            check[i] = false;
        }
    }
}

int main(){
    cin >> M >> N; //NOTE: M is the range, N is the length
    for(int i = 0; i < M; i++){
        cin >> arr[i];
    }
    sort(arr, arr + M);
    for(int i = 0; i < M; i++){
        check[i] = true;
        store.push_back(arr[i]);
        backtracking(1);
        store.pop_back();
        check[i] = false;
    }
}