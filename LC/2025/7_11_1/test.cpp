class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        ranges::sort(intervals);
        vector<vector<int>> ret;
        for (auto &mid : intervals)
        {
            if (!ret.empty() && mid[0] <= ret.back()[1])
            {
                ret.back()[1] = max(ret.back()[1], mid[1]);
            }
            else
            {
                ret.emplace_back(mid);
            }
        }
        return ret;
    }
};