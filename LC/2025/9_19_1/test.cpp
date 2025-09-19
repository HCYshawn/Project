class Solution
{
public:
    string restoreString(string s, vector<int> &indices)
    {
        int l = s.size();
        string ret(l, 0);

        for (int i = 0; i < l; i++)
        {
            ret[indices[i]] = s[i];
        }
        return ret;
    }
};