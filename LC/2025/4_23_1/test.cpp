#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    int countLargestGroup(int n)
    {
        vector<int> arr((to_string(n).size()) * 9 + 1);
        int ret = 0;
        int max_a = 0;
        for (int i = 1; i <= n; i++)
        {
            int j = i;
            int mid = 0;
            while (j)
            {
                mid += j % 10;
                j /= 10;
            }
            arr[mid]++;
            if (arr[mid] > max_a)
            {
                max_a = arr[mid];
                ret = 1;
            }
            else if (arr[mid] == max_a)
            {
                ret++;
            }
        }

        return ret;
    }
};