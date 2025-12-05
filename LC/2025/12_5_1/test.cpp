class Solution
{
public:
    int countPartitions(vector<int> &nums)
    {
        int ret = reduce(nums.begin(), nums.end());
        return ret % 2 ? 0 : nums.size() - 1;
    }
};