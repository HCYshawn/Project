class Solution
{
public:
    int returnToBoundaryCount(vector<int> &nums)
    {
        int ret = 0;
        int mid = 0;
        for (int a : nums)
        {
            mid += a;
            if (mid == 0)
                ret++;
        }
        return ret;
    }
};