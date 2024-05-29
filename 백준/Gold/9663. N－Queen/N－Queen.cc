#include <iostream>
#include <cmath>
using namespace std;

int ans = 0;
int n;
int col[16] = {0};
void queen(int x){
    if(n == x){
        ans++;
        return;
    }
    for(int i = 0; i < n; i++){
        bool flag = false;
        col[x] = i;
        
        //check pass
        for(int j = 0; j < x; j++){
            if(col[x] == col[j] || abs(x - j) == abs(col[x] - col[j]))
                flag = true;
        }
    if(!flag)
        queen(x + 1); //next row
    }
}

int main() {
    cin >> n;
    queen(0);
    cout << ans << endl;
}