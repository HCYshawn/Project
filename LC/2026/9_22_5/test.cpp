class Solution
{
public:
    long long calculateScore(string s)
    {
        long long ret = 0;
        stack<int> stk[26];
        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            if (!stk[25 - c].empty())
            {
                ret += i - stk[25 - c].top();
                stk[25 - c].pop();
            }
            else
            {
                stk[c].push(i);
            }
        }
        return ret;
    }
};