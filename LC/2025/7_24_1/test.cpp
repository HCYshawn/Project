class Solution
{
public:
    int minElement(vector<int> &nums)
    {
        int ret = INT_MAX;
        for (int x : nums)
        {
            int mid = 0;
            while (x)
            {
                mid += x % 10;
                x /= 10;
            }
            ret = min(mid, ret);
        }
        return ret;
    }
};