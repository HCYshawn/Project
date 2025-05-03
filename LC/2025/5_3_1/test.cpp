#include <vector>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int ans = 0;
        for (int x : nums)
        {
            while (x >= 100)
            {
                x /= 100;
            }
            ans += x >= 10;
        }
        return ans;
    }
};