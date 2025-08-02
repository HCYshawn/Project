class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        int has[26]{};
        for (auto s : sentence)
        {
            has[s - 'a']++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (has[i] == 0)
            {
                return false;
            }
        }
        return true;
    }
};