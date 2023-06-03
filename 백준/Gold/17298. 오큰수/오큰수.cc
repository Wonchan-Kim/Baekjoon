/*
fifo 큐 사용
*/

#include <stack>
#include <iostream>
#include <vector>
using namespace::std;

int main(){
    int n;
    cin >> n;
    stack<int> store;
    vector<int> ans(n, -1);
    vector<int> contain;
    for(int i = 0; i < n; i++){
        int input;
        cin >> input;
        contain.push_back(input);
    }
    for(int i = n - 1; i >= 0; i--){
        while(!store.empty() && contain[i] >= store.top()){
            store.pop();
        }
        if(store.empty()){
            ans[i] = -1;
        }
        else{
            ans[i] = store.top();
        } 
        store.push(contain[i]);
    }

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << ' ';
    }
}