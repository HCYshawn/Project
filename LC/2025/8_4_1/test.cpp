class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int ret = 0;
        int mid = nums[0] - 1;
        for (int num : nums)
        {
            mid = max(mid + 1, num);
            ret += mid - num;
        }
        return ret;
    }
};