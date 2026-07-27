class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int ret = 0, mx = 0;
        for (int x : nums)
        {
            ret = max(ret, (mx - 1) * (x - 1));
            mx = max(mx, x);
        }
        return ret;
    }
};