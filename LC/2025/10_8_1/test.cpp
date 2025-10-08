class Solution
{
public:
    int commonFactors(int a, int b)
    {
        int ret = 0;
        int g = gcd(a, b);
        for (int i = 1; i * i <= g; i++)
        {
            if (g % i == 0)
            {
                ++ret;
                if (i * i < g)
                    ++ret;
            }
        }
        return ret;
    }
};