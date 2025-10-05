class Solution
{
public:
    int maxProductDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int s = nums.size();
        int m = nums[s - 1] * nums[s - 2];
        int n = nums[0] * nums[1];
        return m - n;
    }
};