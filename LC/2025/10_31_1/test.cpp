class Solution
{
public:
    vector<int> getSneakyNumbers(vector<int> &nums)
    {
        vector<int> ret;
        int cnt[100] = {0};
        for (int i = 0; i < nums.size(); i++)
        {
            cnt[nums[i]]++;
            if (cnt[nums[i]] > 1)
                ret.push_back(nums[i]);
        }
        return ret;
    }
};