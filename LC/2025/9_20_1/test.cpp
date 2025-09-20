class Solution
{
public:
    int sumOfUnique(vector<int> &nums)
    {
        int mid[101] = {0};
        int ret = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            mid[nums[i]]++;
        }
        for (int i = 0; i < 101; i++)
        {
            if (mid[i] == 1)
            {
                ret += i;
            }
        }
        return ret;
    }
};