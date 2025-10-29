class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        unordered_set<int> cnt;
        int ret = 0;
        int s = 0;
        int left = 0;
        for (int x : nums)
        {
            while (cnt.contains(x))
            {
                cnt.erase(nums[left]);
                s -= nums[left];
                left++;
            }
            cnt.insert(x);
            s += x;
            ret = max(ret, s);
        }
        return ret;
    }
};