class Solution
{
public:
    int percentageLetter(string s, char letter)
    {
        return ranges::count(s, letter) * 100 / s.size();
    }
};