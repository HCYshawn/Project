class Solution
{
public:
    int findMaxK(vector<int> &nums)
    {
        int ret = -1;
        unordered_set<int> cnt;
        for (int x : nums)
        {
            if (cnt.count(-x))
            {
                ret = max(ret, abs(x));
            }
            cnt.insert(x);
        }
        return ret;
    }
};