#include <vector>
using namespace std;

class Solution
{
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
    {
        // 创建一个大小为2的数组s，s[0]表示满意的顾客数，s[1]表示不满意的顾客数
        int s[2]{};
        int mid = 0;
        for (int i = 0; i < customers.size(); i++)
        {
            // 当前顾客不生气，则将其加入满意的顾客数中 or 当前顾客生气，则将其加入不满意的顾客数中
            s[grumpy[i]] += customers[i];
            if (i < minutes - 1)
                continue;

            mid = max(mid, s[1]);

            s[1] -= grumpy[i - minutes + 1] ? customers[i - minutes + 1] : 0;
        }

        return s[0] + mid;
    }
};