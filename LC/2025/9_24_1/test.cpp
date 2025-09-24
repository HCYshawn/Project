class Solution
{
public:
    bool areOccurrencesEqual(string s)
    {
        unordered_map<char, int> mid;
        for (auto ch : s)
        {
            if (!mid.count(ch))
                mid[ch] = 0;
            ++mid[ch];
        }

        int x = s.size() / mid.size();
        for (auto &&[_, v] : mid)
        {
            if (v != x)
                return false;
        }
        return true;
    }
};