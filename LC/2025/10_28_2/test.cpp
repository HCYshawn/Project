class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int n = nums.size();
        int ret = n + 1;
        int s = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            s += nums[i];
            while (s >= target)
            {
                ret = min(ret, i - left + 1);
                s -= nums[left];
                left++;
            }
        }
        return ret <= n ? ret : 0;
    }
};