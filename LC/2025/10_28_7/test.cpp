class Solution
{
public:
    int minRemoval(vector<int> &nums, int k)
    {
        ranges::sort(nums);
        int max_save = 0;
        int left = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            while (1LL * nums[left] * k < nums[i])
            {
                left++;
            }
            max_save = max(max_save, i - left + 1);
        }
        return nums.size() - max_save;
    }
};