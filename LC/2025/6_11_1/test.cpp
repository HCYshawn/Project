class Solution
{
public:
    int minimumBoxes(vector<int> &apple, vector<int> &capacity)
    {
        int sum = reduce(apple.begin(), apple.end());
        sort(capacity.rbegin(), capacity.rend());
        int ret = 0;
        while (sum > 0)
        {
            sum -= capacity[ret++];
        }
        return ret;
    }
};