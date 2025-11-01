class Solution
{
public:
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }
    long long interchangeableRectangles(vector<vector<int>> &rectangles)
    {
        unordered_map<double, int> cnt;
        long long ret = 0;
        for (const auto &mid : rectangles)
        {
            double b = 1.0 * mid[0] / mid[1];
            ret += cnt[b];
            cnt[b]++;
        }
        return ret;
    }
};