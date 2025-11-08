class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int ret = 0;
        int cnt[60]{};
        for (int t : time)
        {
            ret += cnt[(60 - t % 60) % 60];
            cnt[t % 60]++;
        }
        return ret;
    }
};