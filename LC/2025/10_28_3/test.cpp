class Solution
{
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k)
    {
        if (k <= 1)
            return 0;
        int ret = 0;
        int s = 1;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s *= nums[i];
            while (s >= k)
            {
                s /= nums[left];
                left++;
            }
            ret += i - left + 1;
        }
        return ret;
    }
};