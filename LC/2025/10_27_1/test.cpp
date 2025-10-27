class Solution
{
public:
    int numberOfBeams(vector<string> &bank)
    {
        int ret = 0;
        int mid = 0;
        for (auto &row : bank)
        {
            int cnt = ranges::count(row, '1');
            if (cnt > 0)
            {
                ret += mid * cnt;
                mid = cnt;
            }
        }
        return ret;
    }
};