class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n; i++)
        {
            int temp = abs(nums[i]) - 1;
            if (temp >= 0 && temp <= n && nums[temp] > 0)
                nums[temp] = -nums[temp];
        }

        for (int i = 0; i < n; i++)
        {
            if (nums[i] > 0)
                ret.push_back(i + 1);
        }
        return ret;
    }
};