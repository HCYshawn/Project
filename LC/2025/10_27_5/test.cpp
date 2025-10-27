class Solution
{
public:
    int divisorSubstrings(int num, int k)
    {
        long long M = pow(10, k);
        int ret = 0;
        for (int n = num; n >= M / 10; n /= 10)
        {
            int mid = n % M;
            if (mid > 0 && num % mid == 0)
                ret++;
        }

        return ret;
    }
};