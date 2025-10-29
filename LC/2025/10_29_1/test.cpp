class Solution
{
public:
    int smallestNumber(int n)
    {
        return (1 << bit_width((uint32_t)n)) - 1;
    }
};