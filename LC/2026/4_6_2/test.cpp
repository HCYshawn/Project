// 2946 循环移位后的矩阵相似检查

class Solution
{
public:
    bool areSimilar(vector<vector<int>> &mat, int k)
    {
        int n = mat[0].size();
        for (auto &row : mat)
        {
            for (int j = 0; j < n; j++)
            {
                if (row[j] != row[(j + k) % n])
                    return false;
            }
        }
        return true;
    }
};