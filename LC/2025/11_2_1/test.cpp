class Solution
{
public:
    int maximumDifference(vector<int> &nums)
    {
        int ret = 0;
        int pm = INT_MAX;
        for (int x : nums)
        {
            ret = max(ret, x - pm);
            pm = min(pm, x);
        }
        return ret ? ret : -1;
    }
};