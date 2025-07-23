class Solution
{
public:
    int largestAltitude(vector<int> &gain)
    {
        int ret = 0;
        int mid = 0;
        for (int i = 0; i < gain.size(); i++)
        {
            mid += gain[i];
            ret = ret < mid ? mid : ret;
        }
        return ret;
    }
};