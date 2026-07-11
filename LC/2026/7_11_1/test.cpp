class Solution
{
public:
    int minimumDistance(vector<int> &nums)
    {
        unordered_map<int, vector<int>> pos;
        for (int i = 0; i < nums.size(); i++)
        {
            pos[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto &[_, p] : pos)
        {
            for (int i = 2; i < p.size(); i++)
            {
                ans = min(ans, (p[i] - p[i - 2]) * 2);
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};