class Solution
{
public:
    bool judgeCircle(string moves)
    {
        int x = 0, y = 0;
        for (const auto &mid : moves)
        {
            if (mid == 'U')
            {
                y--;
            }
            else if (mid == 'D')
            {
                y++;
            }
            else if (mid == 'L')
            {
                x--;
            }
            else if (mid == 'R')
            {
                x++;
            }
        }
        return x == 0 && y == 0;
    }
};