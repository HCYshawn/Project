class Solution
{
public:
    int countKeyChanges(string s)
    {
        int ret = 0;
        for (int i = 1; i < s.size(); i++)
        {
            ret += (s[i - 1] & 31) != (s[i] & 31);
        }
        return ret;
    }
};