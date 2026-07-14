class Solution
{
public:
    int countTrapezoids(vector<vector<int>> &points)
    {
        const int MOD = 1e9 + 7;
        unordered_map<int, int> cnt;
        for (auto &p : points)
        {
            cnt[p[1]]++;
        }
        long long ret = 0, s = 0;
        for (auto &[_, c] : cnt)
        {
            long long k = 1LL * c * (c - 1) / 2;
            ret += s * k;
            s += k;
        }
        return ret % MOD;
    }
};