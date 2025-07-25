class Solution
{
public:
    int maxSum(vector<int> &nums)
    {
        unordered_set<int> a;
        int ret = 0;
        int m = INT_MIN;
        for (int x : nums)
        {
            if (x < 0)
            {
                m = max(m, x);
            }
            else if (a.insert(x).second)
            {
                ret += x;
            }
        }
        return a.empty() ? m : ret;
    }
};