class Solution
{
public:
    vector<int> leftRightDifference(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ret(n);

        int sum = 0;
        for (int i : nums)
        {
            sum += i;
        }
        int left = 0;
        for (int i = 0; i < n; i++)
        {
            sum -= nums[i];
            ret[i] = abs(sum - left);
            left += nums[i];
        }
        return ret;
    }
};