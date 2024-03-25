#include <iostream>

using namespace std;

int white = 0;
int blue = 0;
bool map[129][129];
void paint(int x, int y, int N){
    int temp_cnt = 0;
    for(int i = x; i < x + N; i++){
        for(int j = y; j < y + N; j++){
            if(map[i][j])
                temp_cnt++;
        }
    }
    if(!temp_cnt){
        white++;
        return;
    }
    if(temp_cnt == N * N){
        blue++;
        return;
    }
    else {
        paint(x,y,N/2);
        paint(x,y + N/2, N/2);
        paint(x + N/2,y,N/2);
        paint(x + N/2,y + N/2,N/2);
    }
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> map[i][j];
        }
    }
    paint(0,0,n);
    cout << white << endl;
    cout << blue << endl;
    return 0;
}