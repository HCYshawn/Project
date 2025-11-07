class Solution
{
public:
    int countNicePairs(vector<int> &nums)
    {
        int mod = 1e9 + 7;
        unordered_map<int, int> cnt;
        int ret = 0;
        for (int x : nums)
        {
            int rev = 0;
            for (int j = x; j != 0; j /= 10)
            {
                rev *= 10;
                rev += j % 10;
            }
            ret = (ret + cnt[x - rev]) % mod;
            cnt[x - rev]++;
        }
        return ret;
    }
};