class Solution
{
public:
    string makeFancyString(string s)
    {
        string ret;
        int mid = 0;
        for (int i = 0; i < s.size(); i++)
        {
            mid++;
            if (mid < 3)
            {
                ret += s[i];
            }
            if (i < s.size() - 1 && s[i] != s[i + 1])
            {
                mid = 0;
            }
        }
        return ret;
    }
};