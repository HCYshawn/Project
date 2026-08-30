class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int n = nums.size();
        int p = 0, q = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < nums[p])
                p = i;
            else if (nums[i] > nums[q])
                q = i;
        }
        if (p > q)
        {
            swap(p, q);
        }
        return min({q + 1, n - p, p + 1 + n - q});
    }
};