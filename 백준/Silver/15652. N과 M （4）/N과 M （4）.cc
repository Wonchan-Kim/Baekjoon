#include <iostream>
#include <vector>

using namespace std;


// TODO: for loop traverse, 1 ~ M 까지의 수로 시작하는 백트래킹 함수 호출
//CHECKLIST: 1. 백트래킹의 조건을 충족하는가? 1)길이 만족 2)이전 수 보다 큼
//CHECKLIST: 2. 백트래킹 함수 구현을 했는가? 1) 벡터에 수를 넣고 재귀 호출 하였는가? 2) 재귀 호출 이후 다시 원래대로 복구 시켰는가?
//CHECKLIST: 3. 전역변수로 할것인가?
  
 
int M, N; //NOTE: M is the range, N is the length
vector<int> store;
int arr[9];

void backtracking(int len) {
    if (len == N) {
        for (int i = 0; i < len; i++) {
            cout << store[i] << ' ';
        }
        cout << '\n';
    } else {
        for (int i = 1; i <= M; i++) {
            if (arr[i] >= store[len - 1]) {
                store.push_back(arr[i]);
                backtracking(len + 1);
                store.pop_back();
            }
        }
    }
}

int main() {
    cin >> M >> N;
    for (int i = 1; i <= M; i++) {
        arr[i] = i;
    }
    for (int i = 1; i <= M; i++) {
        store.push_back(arr[i]);
        backtracking(1);
        store.pop_back();
    }
    return 0;
}
