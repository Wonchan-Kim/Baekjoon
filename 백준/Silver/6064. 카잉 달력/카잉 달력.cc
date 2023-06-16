#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int t;
    cin >> t;
    while(t){
        int M, N;
        cin >> M >> N;
        int x, y;
        cin >> x >> y;
        
        int sum_x[40000] = {0};
        int sum_y[40000] = {0};
        sum_x[0] = x;
        sum_y[0] = y;
        for(int i = 1; i < 40000; i++){
            sum_x[i] += (sum_x[i-1]+M);
        }
        for(int j = 1; j < 40000; j++){
            sum_y[j] += (sum_y[j-1] + N);
        }
        int i = 0;
        bool found = false;
        while(i < 40000){
                found = binary_search(sum_y, sum_y + sizeof(sum_y) / sizeof(int) - 1, sum_x[i]);
                if(found == true){
                    cout << sum_x[i] << endl;
                    break;
                }
                else{
                       // cout << sum_x[i] << endl;;
                        i++;    
                } 
            }
        if(!found)
            cout << -1 << endl;
        t--;
    }
}
