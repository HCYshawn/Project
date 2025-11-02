class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        int ret = -1;
        int max_val[10];
        ranges::fill(max_val, INT_MIN);
        for (int v : nums)
        {
            int max_d = 0;
            for (int x = v; x; x /= 10)
            {
                max_d = max(max_d, x % 10);
            }
            ret = max(ret, v + max_val[max_d]);
            max_val[max_d] = max(max_val[max_d], v);
        }
        return ret;
    }
};