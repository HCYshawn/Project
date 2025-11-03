class Solution
{
public:
    int minCost(string colors, vector<int> &neededTime)
    {
        int n = colors.size();
        int ret = 0;
        int max_t = 0;
        for (int i = 0; i < n; i++)
        {
            int t = neededTime[i];
            ret += t;
            max_t = max(max_t, t);
            if (i == n - 1 || colors[i] != colors[i + 1])
            {
                ret -= max_t;
                max_t = 0;
            }
        }
        return ret;
    }
};