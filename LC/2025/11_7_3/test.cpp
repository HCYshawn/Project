class Solution
{
public:
    int countBeautifulPairs(vector<int> &nums)
    {
        int ret = 0;
        int cnt[10]{};
        for (int x : nums)
        {
            for (int y = 1; y < 10; y++)
            {
                if (cnt[y] && gcd(y, x % 10) == 1)
                    ret += cnt[y];
            }
            while (x >= 10)
            {
                x /= 10;
            }
            cnt[x]++;
        }
        return ret;
    }
};