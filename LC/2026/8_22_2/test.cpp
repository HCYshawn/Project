class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        vector<int> a{nums[0]}, b{nums[1]};
        for (int i = 2; i < nums.size(); i++)
        {
            (a.back() > b.back() ? a : b).push_back(nums[i]);
        }
        a.insert(a.end(), b.begin(), b.end());
        return a;
    }
};