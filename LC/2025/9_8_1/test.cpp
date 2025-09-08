class Solution
{
public:
    int smallestIndex(vector<int> &nums)
    {
        for (int i = 0; i < nums.size(); i++)
        {
            int mid = nums[i];
            int sum = 0;
            while (mid)
            {
                sum += mid % 10;
                mid /= 10;
            }
            if (sum == i)
                return i;
        }
        return -1;
    }
};