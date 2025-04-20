#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> mid(nums1.begin(), nums1.end());
        vector<int> ans;
        for (auto x : nums2)
        {
            if (mid.erase(x))
                ans.push_back(x);
        }
        return ans;
    }
};