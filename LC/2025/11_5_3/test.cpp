class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int ret = 0;
        int mx = values[0];
        for (int i = 1; i < values.size(); i++)
        {
            ret = max(ret, mx + values[i] - i);
            mx = max(mx, values[i] + i);
        }
        return ret;
    }
};