class Solution
{
public:
    long long findTheArrayConcVal(vector<int> &nums)
    {
        long long ret = 0;
        int i = 0;
        int j = nums.size() - 1;
        while (i < j)
        {
            int x = nums[i];
            int y = nums[j];
            while (y)
            {
                x *= 10;
                y /= 10;
            }
            ret += x + nums[j];
            i++;
            j--;
        }
        if (i == j)
        {
            ret += nums[i];
        }
        return ret;
    }
};