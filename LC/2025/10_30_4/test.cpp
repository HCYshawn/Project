class Solution
{
public:
    int lower_bound(vector<int> &nums, int target)
    {
        int left = -1;
        int right = nums.size();
        while (left + 1 < right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target)
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
        }
        return right;
    }
    int searchInsert(vector<int> &nums, int target)
    {
        return lower_bound(nums, target);
    }
};