class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int k = ranges::max(candies) - extraCandies;
        vector<bool> ret;
        ret.reserve(candies.size());
        for (int c : candies)
        {
            ret.push_back(c >= k);
        }
        return ret;
    }
};