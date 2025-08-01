class Solution
{
public:
    int maximumXOR(vector<int> &nums)
    {
        int ret = 0;
        for (int mid : nums)
        {
            ret |= mid;
        }
        return ret;
    }
};