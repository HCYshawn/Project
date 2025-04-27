#include <vector>
using namespace std;
class Solution
{
public:
    int countSubarrays(vector<int> &nums)
    {
        int ret = 0;
        for (int i = 1; i < nums.size() - 1; i++)
        {
            if ((nums[i - 1] + nums[i + 1]) * 2 == nums[i])
                ret++;
        }
        return ret;
    }
};