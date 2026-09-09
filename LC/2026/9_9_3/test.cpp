class Solution
{
public:
    int countDigitOne(int n)
    {
        long long count = 0;
        long long factor = 1;
        while (factor <= n)
        {
            long long high = n / (factor * 10);
            long long cur = (n / factor) % 10;
            long long low = n % factor;

            if (cur == 0)
                count += high * factor;
            else if (cur == 1)
                count += high * factor + low + 1;
            else
                count += (high + 1) * factor;

            factor *= 10;
        }
        return (int)count;
    }
};