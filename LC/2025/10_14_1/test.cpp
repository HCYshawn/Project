class Solution
{
public:
    bool hasIncreasingSubarrays(vector<int> &nums, int k)
    {
        int n = nums.size();
        int cnt = 1, p = 0, ret = 0;
        for (int i = 1; i < n; ++i)
        {
            if (nums[i] > nums[i - 1])
                ++cnt;
            else
            {
                p = cnt;
                cnt = 1;
            }
            ret = max(ret, min(p, cnt));
            ret = max(ret, cnt / 2);
        }
        return ret >= k;
    }
};