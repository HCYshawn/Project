class Solution
{
public:
    vector<bool> prefixesDivBy5(vector<int> &nums)
    {
        vector<bool> ret(nums.size());
        int x = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            x = ((x << 1) + nums[i]) % 5;
            ret[i] = x == 0;
        }
        return ret;
    }
};