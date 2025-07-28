class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        int ret = ranges::count_if(word, ::isupper);
        return ret == 0 || ret == word.size() || ret == 1 && isupper(word[0]);
    }
};