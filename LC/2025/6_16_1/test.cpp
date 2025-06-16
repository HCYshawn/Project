class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        if (nums.size() <= 1)
            return -1;
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                ret = max(ret, nums[i] - nums[j]);
            }
        }
        if (ret == 0)
            return -1;
        return ret;
    }
};