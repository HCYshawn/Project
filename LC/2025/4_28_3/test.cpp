class Solution
{
public:
    double myPow(double x, int n)
    {
        double ans = 1;
        long long y = n;
        if (y < 0)
        {
            y = -y;
            x = 1 / x;
        }
        while (y)
        {
            if (y & 1)
            {
                ans *= x;
            }
            x *= x;
            y >>= 1;
        }
        return ans;
    }
};