class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int ret = 0;
        int sl = stones.size();
        for (int i = 0; i < sl; i++)
        {
            for (char c : jewels)
            {
                if (c == stones[i])
                {
                    ret++;
                    break;
                }
            }
        }
        return ret;
    }
};