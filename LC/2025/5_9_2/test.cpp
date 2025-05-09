#include <vector>
using namespace std;

class Solution
{
public:
    char nextGreatestLetter(vector<char> &letters, char target)
    {
        int left = 0;
        int right = letters.size() - 1;
        char ret = letters[0];
        while (left <= right)
        {
            int mid = right - left / 2 + left;
            if (letters[mid] == target)
            {
                left = mid + 1;
            }
            else if (letters[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                ret = letters[mid];
                right = mid - 1;
            }
        }
        return ret;
    }
};