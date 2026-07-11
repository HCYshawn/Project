class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        int cnt['z' + 1]{};
        for (char ch : text)
        {
            cnt[ch]++;
        }
        return min({cnt['a'], cnt['b'], cnt['l'] / 2, cnt['n'], cnt['o'] / 2});
    }
};
