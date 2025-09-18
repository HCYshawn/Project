class Solution
{
public:
    int maxProduct(int n)
    {
        string s = to_string(n);
        ranges::sort(s);
        int m = s.size();
        return (s[m - 1] - '0') * (s[m - 2] - '0');
    }
};