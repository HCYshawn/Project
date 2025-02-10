#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution
{
public:
    int sumOfEncryptedInt(vector<int> &nums)
    {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int mid = nums[i];
            int max = 0;
            int j = 0;
            while (mid)
            {
                max = max > mid % 10 ? max : mid % 10;
                mid /= 10;
                j++;
            }
            for (int k = 0; k < j; k++)
            {
                sum += max * pow(10, k);
            }
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {123, 456, 789};
    cout << s.sumOfEncryptedInt(nums) << endl;
    return 0;
}