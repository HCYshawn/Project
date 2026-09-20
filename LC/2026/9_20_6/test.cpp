class Solution
{
public:
    int reverseDegree(string s)
    {
        int ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            ret += (27 - (s[i] - 'a' + 1)) * (i + 1);
        }
        return ret;
    }
};