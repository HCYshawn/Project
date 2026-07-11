class Solution
{
public:
    long long sumAndMultiply(int n)
    {
        long long ret = 0;
        int sum = 0;
        int i = 0;
        while (n)
        {
            int tmp = n % 10;
            if (tmp != 0)
            {
                ret += tmp * pow(10, i);
                i++;
            }
            sum += tmp;
            n /= 10;
        }
        ret *= sum;
        return ret;
    }
};