class Solution
{
public:
    int buyChoco(vector<int> &prices, int money)
    {
        int m1 = INT_MAX;
        int m2 = INT_MAX;
        for (auto p : prices)
        {
            if (p < m1)
            {
                m2 = m1;
                m1 = p;
            }
            else if (p < m2)
            {
                m2 = p;
            }
        }
        return money < m1 + m2 ? money : money - m1 - m2;
    }
};