class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int s = reduce(cardPoints.begin(), cardPoints.begin() + k);
        int ret = s;
        for (int i = 1; i <= k; i++)
        {
            s += cardPoints[cardPoints.size() - i] - cardPoints[k - i];
            ret = max(ret, s);
        }
        return ret;
    }
};