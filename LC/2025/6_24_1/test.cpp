class Solution
{
public:
    int countAsterisks(string s)
    {
        bool mid = true;
        int ret = 0;
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i];
            if (c == '|')
            {
                mid = !mid;
            }
            else if (c == '*' && mid)
            {
                ret++;
            }
        }
        return ret;
    }
};