class Solution
{
public:
    int findPermutationDifference(string s, string t)
    {
        int pos[26];
        for (int i = 0; i < s.length(); i++)
        {
            pos[s[i] - 'a'] = i;
        }

        int ret = 0;
        for (int i = 0; i < t.length(); i++)
        {
            ret += abs(i - pos[t[i] - 'a']);
        }
        return ret;
    }
};