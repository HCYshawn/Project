class Solution
{
public:
    string freqAlphabets(string s)
    {
        string ret;
        for (int i = 0; i < s.size(); i++)
        {
            if (i + 2 < s.size() && s[i + 2] == '#')
            {
                ret += char((s[i] - '0') * 10 + (s[i + 1] - '1') + 'a');
                i += 2;
            }
            else
            {
                ret += char(s[i] - '1' + 'a');
            }
        }
        return ret;
    }
};