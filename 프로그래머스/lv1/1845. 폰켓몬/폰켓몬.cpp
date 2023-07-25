#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> hash;
    int size = nums.size() / 2;
    for(int i = 0; i < nums.size(); i++){
        hash.insert(nums[i]);
    }
     
    return hash.size() >= size ? size : hash.size();
}