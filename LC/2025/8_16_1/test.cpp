class Solution
{
public:
    int maximum69Number(int num)
    {
        string s = to_string(num);
        int i = s.find('6');
        if (i == string::npos)
        {
            return num;
        }
        s[i] = '9';
        return stoi(s);
    }
};