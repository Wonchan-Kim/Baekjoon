#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool findNextPermutation(vector<int>& nums) {
    int n = nums.size();

    // Find the largest index i such that nums[i] < nums[i+1]
    int i = n - 2;
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i < 0) {
        return false;  // No next permutation
    }

    // Find the largest index j such that nums[j] > nums[i]
    int j = n - 1;
    while (nums[j] <= nums[i]) {
        j--;
    }

    // Swap nums[i] and nums[j]
    swap(nums[i], nums[j]);

    // Sort the suffix starting from index i+1
    sort(nums.begin() + i + 1, nums.end());

    return true;
}

int main() {
    int N;
    cin >> N;

    vector<int> nums(N);
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // Find the next lexicographically greater permutation
    if (findNextPermutation(nums)) {
        for (int num : nums) {
            cout << num << ' ';
        }
    } else {
        cout << -1;
    }

    return 0;
}
