class Solution
{
public:
    int countOperations(int num1, int num2)
    {
        int ret = 0;
        while (num2 > 0)
        {
            ret += num1 / num2;
            num1 %= num2;
            swap(num1, num2);
        }
        return ret;
    }
};