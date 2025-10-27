class Solution
{
public:
    vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
    {
        int last = -k - 1;
        for (int i = k - 1; i >= 0; i--)
        {
            if (nums[i] == key)
            {
                last = i;
                break;
            }
        }

        vector<int> ret;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i + k < nums.size() && nums[i + k] == key)
            {
                last = i + k;
            }
            if (last >= i - k)
            {
                ret.push_back(i);
            }
        }
        return ret;
    }
};