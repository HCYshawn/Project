class Solution
{
public:
    long long countBadPairs(vector<int> &nums)
    {
        int n = nums.size();
        long long ret = 1LL * n * (n - 1) / 2;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++)
        {
            ret -= cnt[nums[i] - i]++;
        }
        return ret;
    }
};