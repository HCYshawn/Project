class Solution
{
public:
    bool digitCount(string num)
    {
        vector<int> mid(10, 0);
        for (char c : num)
        {
            mid[c - '0']++;
        }
        for (int i = 0; i < num.size(); i++)
        {
            if (mid[i] != num[i] - '0')
                return false;
        }
        return true;
    }
};