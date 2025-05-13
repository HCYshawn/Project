class Solution
{
public:
    int getSum(int a, int b)
    {
        while (b != 0)
        {
            unsigned int mid = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = mid;
        }
        return a;
    }
};