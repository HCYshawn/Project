class Solution
{
public:
    string firstPalindrome(vector<string> &words)
    {
        auto isp = [](const string &word) -> bool
        {
            int n = word.size();
            int l = 0;
            int r = n - 1;
            while (l < r)
            {
                if (word[l] != word[r])
                {
                    return false;
                }
                l++;
                --r;
            }
            return true;
        };
        for (const string &word : words)
        {
            if (isp(word))
            {
                return word;
            }
        }
        return "";
    }
};