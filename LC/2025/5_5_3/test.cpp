#include <string>
using namespace std;

class Solution
{
public:
    int minimumChairs(string s)
    {
        int ret = 0;
        int mid = 0;
        for (auto e : s)
        {
            if (e == 'E')
            {
                mid++;
                ret = ret < mid ? mid : ret;
            }
            else
            {
                mid--;
            }
        }
        return ret;
    }
};