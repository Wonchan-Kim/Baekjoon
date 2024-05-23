#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> arr(n);
    int max = -10000001;
    int min = 10000001;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        if(max < arr[i])
            max = arr[i];
        if(min > arr[i])
            min = arr[i];
    }
    cout << min << " " << max << endl;
}