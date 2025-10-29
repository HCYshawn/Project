class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        int ret = 0;
        int left = 0;
        int cnt0 = 0;
        for (int right = 0; right < nums.size(); right++)
        {
            cnt0 += 1 - nums[right];
            while (cnt0 > k)
            {
                cnt0 -= 1 - nums[left];
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};