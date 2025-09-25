class Solution
{
public:
    vector<vector<int>> minimumAbsDifference(vector<int> &arr)
    {
        int n = arr.size();
        sort(arr.begin(), arr.end());

        int best = INT_MAX;
        vector<vector<int>> ret;
        for (int i = 0; i < n - 1; i++)
        {
            int mid = arr[i + 1] - arr[i];
            if (mid < best)
            {
                best = mid;
                ret = {{arr[i], arr[i + 1]}};
            }
            else if (mid == best)
            {
                ret.emplace_back(initializer_list<int>{arr[i], arr[i + 1]});
            }
        }
        return ret;
    }
};