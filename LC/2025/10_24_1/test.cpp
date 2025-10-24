class Solution
{
public:
    int vowelStrings(vector<string> &words, int left, int right)
    {
        const string str = "aeiou";
        int ret = 0;
        for (int i = left; i <= right; i++)
        {
            string &mid = words[i];
            ret += str.find(mid[0]) != string::npos &&
                   str.find(mid.back()) != string::npos;
        }
        return ret;
    }
};