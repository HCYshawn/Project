class Solution
{
public:
    int elevatorRequests(int n, vector<int> &requests)
    {
        int ret = 0;
        int tmp = 0;
        for (int i = 0; i < requests.size(); i++)
        {
            ret += abs(requests[i] - tmp);
            tmp = requests[i];
        }
        return ret;
    }
};