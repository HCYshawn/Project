class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int n = s.size();
        int ret = 0;
        int left = 0;
        unordered_map<char, int> cnt;
        for (int right = 0; right < n; right++)
        {
            char c = s[right];
            cnt[c]++;
            while (cnt[c] > 1)
            {
                cnt[s[left]]--;
                left++;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};