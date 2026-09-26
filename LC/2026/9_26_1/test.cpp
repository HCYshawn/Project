class Solution
{
public:
    int evenNumberBitwiseORs(vector<int> &nums)
    {
        int ret = 0;
        for (int x : nums)
        {
            if (x % 2 == 0)
            {
                ret |= x;
            }
        }
        return ret;
    }
};