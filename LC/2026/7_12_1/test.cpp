class Solution
{
public:
    vector<int> arrayRankTransform(vector<int> &arr)
    {
        vector<int> t = arr;
        int k = 1;
        ranges::sort(t);
        int n = t.size();
        unordered_map<int, int> mp;
        for (int x : t)
        {
            if (!mp.count(x))
            {
                mp[x] = mp.size() + 1;
            }
        }
        for (int &x : arr)
        {
            x = mp[x];
        }
        return arr;
    }
};