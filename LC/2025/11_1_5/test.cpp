class Solution
{
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes)
    {
        int ret = 0;
        int cnt[10][10]{};
        for (auto &mid : dominoes)
        {
            auto [a, b] = minmax(mid[0], mid[1]);
            ret += cnt[a][b]++;
        }
        return ret;
    }
};