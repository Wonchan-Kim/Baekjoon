#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    long long target;
    cin >> target;
    
    int size_1;
    cin >> size_1;
    
    vector<long long> arr1(size_1);
    for(int i = 0; i < size_1; i++){
        cin >> arr1[i];
    }
    
    int size_2;
    cin >> size_2;
    
    vector<long long> arr2(size_2);
    for(int i = 0; i < size_2; i++){
        cin >> arr2[i];
    }

    vector<long long> sumA;
    vector<long long> sumB;

    for(int i = 0; i < size_1; i++){
        long long sum = arr1[i];
        sumA.push_back(sum);
        for(int j = i + 1; j < size_1; j++){
            sum += arr1[j];
            sumA.push_back(sum);
        }
    }

    for(int i = 0; i < size_2; i++){
        long long sum = arr2[i];
        sumB.push_back(sum);
        for(int j = i + 1; j < size_2; j++){
            sum += arr2[j];
            sumB.push_back(sum);
        }
    }

    sort(sumB.begin(), sumB.end());

    long long ans = 0;
    for(int i = 0 ; i < sumA.size(); i++){
        long long left = target - sumA[i];
        int idx1 = lower_bound(sumB.begin(), sumB.end(), left) - sumB.begin();
        int idx2 = upper_bound(sumB.begin(), sumB.end(), left) - sumB.begin();
        ans += (idx2 - idx1);
    }
    
    cout << ans << endl;
    return 0;
}
