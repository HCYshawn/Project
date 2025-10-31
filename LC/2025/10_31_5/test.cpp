class Solution
{
public:
    vector<int> answerQueries(vector<int> &nums, vector<int> &queries)
    {
        ranges::sort(nums);
        partial_sum(nums.begin(), nums.end(), nums.begin());
        for (int &q : queries)
        {
            q = ranges::upper_bound(nums, q) - nums.begin();
        }
        return queries;
    }
};