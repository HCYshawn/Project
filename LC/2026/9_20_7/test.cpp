class Solution
{
public:
    vector<string> buildArray(vector<int> &target, int n)
    {
        vector<string> ret;
        int j = 0;
        int m = target.back();
        for (int i = 1; i <= m; i++)
        {
            ret.push_back("Push");
            if (target[j] == i)
            {
                j++;
            }
            else
            {
                ret.push_back("Pop");
            }
        }
        return ret;
    }
};