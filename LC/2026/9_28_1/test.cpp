class Solution
{
public:
    int maxDepth(string s)
    {
        int ret = 0;
        int m = 0;
        for (auto c : s)
        {
            if (c == '(')
            {
                m++;
                ret = max(m, ret);
            }
            else if (c == ')')
            {
                m--;
            }
        }
        return ret;
    }
};