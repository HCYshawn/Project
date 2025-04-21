#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int ret(int x)
    {
        int ans = 0;
        while (x)
        {
            ans += x % 10;
            x /= 10;
        }
        return ans;
    }
    int maximumSum(vector<int> &nums)
    {
        int ans = -1;
        int mx[82]{};
        for (int i = 0; i < nums.size(); i++)
        {
            int s = ret(nums[i]);
            if (mx[s])
            {
                ans = max(ans, mx[s] + nums[i]);
            }
            mx[s] = max(mx[s], nums[i]);
        }
        return ans;
    }
};