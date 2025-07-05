class Solution
{
public:
    int findLucky(vector<int> &arr)
    {
        int ret = -1;
        unordered_map<int, int> cnt;
        for (int x : arr)
        {
            cnt[x]++;
        }

        for (auto &[x, c] : cnt)
        {
            if (x == c)
            {
                ret = max(ret, x);
            }
        }
        return ret;
    }
};