#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows < 2)
            return s;
        vector<string> row(numRows);
        int i = 0;
        int flag = -1;
        for (char c : s)
        {
            row[i].push_back(c);
            if (i == 0 || i == numRows - 1)
            {
                flag = -flag;
            }
            i += flag;
        }

        string ret;
        for (const string &mid : row)
            ret += mid;
        return ret;
    }
};