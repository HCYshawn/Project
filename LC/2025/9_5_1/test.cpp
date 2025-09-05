class Solution
{
public:
    int numberOfMatches(int n)
    {
        int ret = 0;
        while (n != 1)
        {
            if (n % 2 == 1)
            {
                ret += (n - 1) / 2;
                n = (n - 1) / 2 + 1;
            }
            else
            {
                ret += n / 2;
                n /= 2;
            }
        }
        return ret;
    }
};