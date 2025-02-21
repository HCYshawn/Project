#include <iostream>
using namespace std;

class Solution
{
public:
    int countDigits(int num)
    {
        int ret = 0;
        int mid = num;
        while (mid)
        {
            if (num % (mid % 10) == 0)
            {
                ret++;
            }

            mid /= 10;
        }
        return ret;
    }
};