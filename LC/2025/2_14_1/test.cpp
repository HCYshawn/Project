#include <iostream>
using namespace std;

class Solution
{
public:
    int alternateDigitSum(int n)
    {
        int ret = 0;
        int k = 0;
        int mid = n;
        while (mid)
        {
            mid /= 10;
            k++;
        }
        while (k)
        {
            if (k % 2)
                ret += n % 10;
            else
                ret -= n % 10;
            n /= 10;
            k--;
        }
        return ret;
    }
};