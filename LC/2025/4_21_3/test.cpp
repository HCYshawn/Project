#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxSum(vector<int> &nums, int m, int k)
    {
        long long ret = 0;
        long long mid = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++)
        {
            mid += nums[i];
            cnt[nums[i]]++;
            if (i < k - 1)
                continue;
            if (cnt.size() >= m)
                ret = max(ret, mid);
            mid -= nums[i - k + 1];
            if (--cnt[nums[i - k + 1]] == 0)
            {
                cnt.erase(nums[i - k + 1]);
            }
        }
        return ret;
    }
};