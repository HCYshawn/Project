class Solution
{
public:
    int deleteGreatestValue(vector<vector<int>> &grid)
    {
        int ret = 0;
        for (auto &row : grid)
        {
            sort(row.begin(), row.end());
        }
        int n = grid[0].size();
        for (int j = 0; j < n; j++)
        {
            int mid = 0;
            for (auto &row : grid)
            {
                mid = max(mid, row[j]);
            }
            ret += mid;
        }
        return ret;
    }
};