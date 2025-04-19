#include <vector>
#include <algorithm>
#include <ranges>
using namespace std;

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        ranges::sort(nums);
        long long ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            auto r = upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
            auto l = lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            ret += r - l;
        }
        return ret;
    }
};