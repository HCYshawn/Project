class Solution
{
public:
    int maximumLengthSubstring(string s)
    {
        int n = s.size();
        int ret = 0;
        int left = 0;
        unordered_map<char, int> cnt;
        for (int i = 0; i < n; i++)
        {
            char c = s[i];
            cnt[c]++;
            while (cnt[c] > 2)
            {
                cnt[s[left]]--;
                left++;
            }
            ret = max(ret, i - left + 1);
        }
        return ret;
    }
};