class Solution
{
public:
    bool isValid(string word)
    {
        if (word.size() < 3)
            return false;
        bool mid[2]{};
        for (auto s : word)
        {
            if (isalpha(s))
            {
                s = tolower(s);
                mid[s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u'] = true;
            }
            else if (!isdigit(s))
            {
                return false;
            }
        }
        return mid[0] && mid[1];
    }
};