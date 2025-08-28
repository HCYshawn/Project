class Solution
{
public:
    int mostWordsFound(vector<string> &sentences)
    {
        int ret = 0;
        for (const string &str : sentences)
        {
            int mid = count(str.begin(), str.end(), ' ') + 1;
            ret = max(mid, ret);
        }
        return ret;
    }
};