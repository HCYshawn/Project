class Solution
{
public:
    int maxFrequencyElements(vector<int> &nums)
    {
        int ret = 0;
        int m = 0;
        unordered_map<int, int> cnt;
        for (int x : nums)
        {
            int mid = ++cnt[x];
            if (mid > m)
            {
                m = ret = mid;
            }
            else if (mid == m)
            {
                ret += mid;
            }
        }
        return ret;
    }
};