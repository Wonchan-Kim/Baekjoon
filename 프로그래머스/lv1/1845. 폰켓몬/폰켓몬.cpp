#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> nums)
{
    unordered_set<int> hash(nums.begin(), nums.end());
    int size = nums.size() / 2;
    
    return hash.size() >= size ? size : hash.size();
}