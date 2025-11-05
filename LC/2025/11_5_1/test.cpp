class Solution
{
public:
    int maxDistance(vector<vector<int>> &arrays)
    {
        int ret = 0;
        int mn = INT_MAX / 2;
        int mx = INT_MIN / 2;
        for (auto &a : arrays)
        {
            ret = max({ret, a.back() - mn, mx - a[0]});
            mn = min(mn, a[0]);
            mx = max(mx, a.back());
        }
        return ret;
    }
};