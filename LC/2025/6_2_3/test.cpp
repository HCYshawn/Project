class Solution
{
public:
    int reverseDegree(string s)
    {
        int ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ret += ('z' - s[i] + 1) * (i + 1);
        }
        return ret;
    }
};