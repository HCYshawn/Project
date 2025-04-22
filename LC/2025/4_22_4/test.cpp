#include <vector>
#include <reduce>
using namespace std;

class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> ans(n);
        int r = k > 0 ? k + 1 : n;
        k = abs(k);
        int s = reduce(code.begin() + r - k, code.begin() + r);
        for (int i = 0; i < n; i++)
        {
            ans[i] = s;
            s += code[r % n] - code[(r - k) % n];
            r++;
        }
        return ans;
    }
};