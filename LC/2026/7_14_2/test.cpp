class Solution
{
public:
    int minAbsoluteDifference(vector<int> &nums)
    {
        int n = nums.size();
        int ret = n;
        int last[2] = {-n, -n};
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (x > 0)
            {
                x--;
                ret = min(ret, i - last[x ^ 1]);
                last[x] = i;
            }
        }
        return ret == n ? -1 : ret;
    }
};