class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        unordered_map<int, int> cnt;
        for (int x : nums1)
        {
            for (int y : nums2)
            {
                cnt[x + y]++;
            }
        }

        int ret = 0;
        for (int x : nums3)
        {
            for (int y : nums4)
            {
                ret += cnt[-x - y];
            }
        }
        return ret;
    }
};