class Solution
{
public:
    int countValidSelections(vector<int> &nums)
    {
        int total = reduce(nums.begin(), nums.end());
        int ret = 0;
        int mid = 0;
        for (int x : nums)
        {
            if (x)
                mid += x;
            else if (mid * 2 == total)
                ret += 2;
            else if (abs(mid * 2 - total) == 1)
                ret++;
        }
        return ret;
    }
};