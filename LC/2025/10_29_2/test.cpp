class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int ret = 0;
        int left = 0;
        unordered_map<int, int> cnt;
        for (int right = 0; right < fruits.size(); right++)
        {
            cnt[fruits[right]]++;
            while (cnt.size() > 2)
            {
                int out = fruits[left];
                cnt[out]--;
                if (cnt[out] == 0)
                    cnt.erase(out);
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};