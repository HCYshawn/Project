class Solution
{
public:
    int minOperations(vector<int> &nums, int x)
    {
        int target = reduce(nums.begin(), nums.end()) - x;
        if (target < 0)
        {
            return -1;
        }

        int ret = -1, left = 0, s = 0, n = nums.size();
        for (int right = 0; right < n; right++)
        {
            s += nums[right];
            while (s > target)
            {
                s -= nums[left];
                left++;
            }
            if (s == target)
            {
                ret = max(ret, right - left + 1);
            }
        }
        return ret < 0 ? -1 : n - ret;
    }
};