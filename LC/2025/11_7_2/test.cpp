class Solution
{
public:
    long long maximumProduct(vector<int> &nums, int m)
    {
        long long ret = LLONG_MIN;
        int mn = INT_MAX;
        int mx = INT_MIN;
        for (int i = m - 1; i < nums.size(); i++)
        {
            int y = nums[i - m + 1];
            mn = min(mn, y);
            mx = max(mx, y);
            long long x = nums[i];
            ret = max({ret, x * mn, x * mx});
        }
        return ret;
    }
};