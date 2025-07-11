class Solution
{
public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        ranges::sort(meetings);
        int start = 1;
        int end = 0;
        for (auto &p : meetings)
        {
            if (p[0] > end)
            {
                days -= end - start + 1;
                start = p[0];
            }
            end = max(end, p[1]);
        }
        days -= end - start + 1;
        return days;
    }
};