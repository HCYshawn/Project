class Solution
{
public:
    int maxFreqSum(string s)
    {
        int mid[26]{};
        for (auto b : s)
        {
            mid[b - 'a']++;
        }
        int max_x = 0;
        for (auto b : string("aeiou"))
        {
            max_x = max(max_x, mid[b - 'a']);
            mid[b - 'a'] = 0;
        }

        int max_y = 0;
        for (int i = 0; i < 26; i++)
        {
            max_y = max_y > mid[i] ? max_y : mid[i];
        }
        return max_x + max_y;
    }
};