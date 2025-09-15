class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        unordered_set<char> broken;
        for (char ch : brokenLetters)
        {
            broken.insert(ch);
        }
        int ret = 0;
        bool flag = true;
        for (char ch : text)
        {
            if (ch == ' ')
            {
                if (flag)
                    ++ret;
                flag = true;
            }
            else if (broken.count(ch))
            {
                flag = false;
            }
        }
        if (flag)
            ret++;
        return ret;
    }
};
