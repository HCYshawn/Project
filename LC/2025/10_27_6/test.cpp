class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, int> last;
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (last.contains(x) && i - last[x] <= k)
                return true;
            last[x] = i;
        }
        return false;
    }
};