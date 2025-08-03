class Solution
{
public:
    int sumOfGoodNumbers(vector<int> &nums, int k)
    {
        int ret = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int mid = nums[i];
            if ((i < k || mid > nums[i - k]) && (i + k >= n || mid > nums[i + k]))
                ret += mid;
        }
        return ret;
    }
};