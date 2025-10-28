class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int n = nums.size();
        int ret = 0;
        int cnt0 = 0;
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            cnt0 += 1 - nums[i];
            while (cnt0 > 1)
            {
                cnt0 -= 1 - nums[left];
                left++;
            }
            ret = max(ret, i - left);
        }
        return ret;
    }
};