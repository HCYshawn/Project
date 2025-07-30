class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        int m = ranges::max(nums);
        int ret = 0;
        int mid = 0;
        for (int x : nums)
        {
            if (x == m)
            {
                mid++;
                ret = max(ret, mid);
            }
            else
            {
                mid = 0;
            }
        }
        return ret;
    }
};