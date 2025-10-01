class Solution
{
public:
    int numWaterBottles(int numBottles, int numExchange)
    {
        int ret = numBottles;
        int mid = numBottles;
        while (mid >= numExchange)
        {
            mid -= numExchange;
            ++ret;
            ++mid;
        }

        return ret;
    }
};