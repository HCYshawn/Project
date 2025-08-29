class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> sa;
        for (auto &p : paths)
        {
            sa.insert(p[0]);
        }
        for (auto &p : paths)
        {
            if (!sa.contains(p[1]))
            {
                return p[1];
            }
        }
        return "";
    }
};