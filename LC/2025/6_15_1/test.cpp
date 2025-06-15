class Solution
{
public:
    bool isBalanced(string num)
    {
        int x = 0;
        int y = 0;
        for (int i = 0; i < num.size(); i++)
        {
            if (i % 2)
                x += num[i] - '0';
            else
                y += num[i] - '0';
        }
        return x == y;
    }
};