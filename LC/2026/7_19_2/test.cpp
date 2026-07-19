class Solution
{
public:
    string smallestSubsequence(string s)
    {
        int left[26]{};
        for (char c : s)
        {
            left[c - 'a']++;
        }
        string ret;
        bool int_ret[26]{};
        for (char c : s)
        {
            left[c - 'a']--;
            if (int_ret[c - 'a'])
            {
                continue;
            }
            while (!ret.empty() && c < ret.back() && left[ret.back() - 'a'])
            {
                int_ret[ret.back() - 'a'] = false;
                ret.pop_back();
            }
            ret += c;
            int_ret[c - 'a'] = true;
        }

        return ret;
    }
};