class Solution
{
public:
    vector<int> maxSubsequence(vector<int> &nums, int k)
    {
        vector<int> ret(nums.size());
        ranges::iota(ret, 0);
        ranges::sort(ret, {}, [&](int i)
                     { return -nums[i]; });

        ret.resize(k);
        ranges::sort(ret);

        for (int &i : ret)
        {
            i = nums[i];
        }
        return ret;
    }
};