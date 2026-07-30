class Solution
{
public:
    int minimumPushes(string word)
    {
        int n = word.length();
        int k = n / 8;
        return (k * 4 + n % 8) * (k + 1);
    }
};