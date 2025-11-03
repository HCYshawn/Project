class Solution
{
public:
    int maxOperations(vector<int> &nums, int k)
    {
        unordered_map<int, int> cnt;
        int ret = 0;
        for (int x : nums)
        {
            auto it = cnt.find(k - x);
            if (it != cnt.end() && it->second)
            {
                it->second--;
                ret++;
            }
            else
            {
                cnt[x]++;
            }
        }
        return ret;
    }
};