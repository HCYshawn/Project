class Solution
{
public:
    int smallestRangeI(vector<int> &nums, int k)
    {
        auto [m, M] = ranges::minmax(nums);
        return max(M - m - k * 2, 0);
    }
};