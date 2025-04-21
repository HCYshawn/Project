#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int> &nums, int k)
    {
        long long ret = 0;
        long long sum = 0;
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            cnt[nums[i]]++;
            if (i < k - 1)
                continue;
            if (cnt.size() == k)
                ret = max(ret, sum);

            int out = nums[i - k + 1];
            sum -= out;
            if (--cnt[out] == 0)
            {
                cnt.erase(out);
            }
        }
        return ret;
    }
};