class Solution
{
public:
    bool checkDivisibility(int n)
    {
        int tmp = n;
        int sum = 0;
        int sub = 1;
        while (tmp)
        {
            sum += tmp % 10;
            sub *= tmp % 10;
            tmp /= 10;
        }
        return n % (sum + sub) == 0;
    }
};