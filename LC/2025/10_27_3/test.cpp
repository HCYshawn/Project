class Solution
{
public:
    int minArrivalsToDiscard(vector<int> &arrivals, int w, int m)
    {
        unordered_map<int, int> cnt;
        int ret = 0;
        for (int i = 0; i < arrivals.size(); i++)
        {
            int &x = arrivals[i];
            if (cnt[x] == m)
            {
                x = 0;
                ret++;
            }
            else
            {
                cnt[x]++;
            }
            int left = i + 1 - w;
            if (left >= 0)
            {
                cnt[arrivals[left]]--;
            }
        }
        return ret;
    }
};