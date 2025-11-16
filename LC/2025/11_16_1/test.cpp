class Solution
{
public:
    int numSub(string s)
    {
        constexpr int MOD = 1'000'000'007;
        long long ret = 0;
        int last0 = -1;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '0')
                last0 = i;
            else
            {
                ret += i - last0;
            }
        }
        return ret % MOD;
    }
};