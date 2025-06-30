class Solution
{
public:
    int findLHS(vector<int> &nums)
    {
        int ret = 0;
        unordered_map<int, int> cnt;
        for (int x : nums)
        {
            cnt[x]++;
        }
        for (auto &[x, c] : cnt)
        {
            if (cnt.contains(x + 1))
            {
                ret = max(ret, c + cnt[x + 1]);
            }
        }
        return ret;
    }
};