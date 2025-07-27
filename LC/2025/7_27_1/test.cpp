class Solution
{
public:
    int countHillValley(vector<int> &nums)
    {
        int m = ranges::unique(nums).begin() - nums.begin();
        int ret = 0;
        for (int i = 1; i < m - 1; i++)
        {
            if ((nums[i - 1] < nums[i]) == (nums[i] > nums[i + 1]))
            {
                ret++;
            }
        }
        return ret;
    }
};