class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> idx;
        for (int j = 0;; j++)
        {
            auto it = idx.find(target - nums[j]);
            if (it != idx.end())
            {
                return {it->second, j};
            }
            idx[nums[j]] = j;
        }
    }
};