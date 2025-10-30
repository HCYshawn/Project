class Solution
{
public:
    int maximumBeauty(vector<int> &nums, int k)
    {
        ranges::sort(nums);
        int ret = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            while (nums[right] - nums[left] > k * 2)
            {
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};