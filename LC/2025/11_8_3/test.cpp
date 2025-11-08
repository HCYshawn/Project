class Solution
{
public:
    vector<int> findMissingElements(vector<int> &nums)
    {
        int mn = ranges::min(nums);
        int mx = ranges::max(nums);
        unordered_set<int> st(nums.begin(), nums.end());

        vector<int> ret;
        for (int i = mn + 1; i < mx; i++)
        {
            if (!st.contains(i))
                ret.push_back(i);
        }
        return ret;
    }
};