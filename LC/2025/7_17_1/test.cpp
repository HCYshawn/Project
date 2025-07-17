class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> ret;
        int mid = n / 2;

        for (int i = 1; i <= mid; i++)
        {
            ret.push_back(i);
            ret.push_back(-i);
        }

        if (n % 2 != 0)
        {
            ret.push_back(0);
        }

        return ret;
    }
};