class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int ret = 0;
        for(auto str :details)
        {
            ret +=(str[11]-'0')*10+str[12]-'0'>60;
        }
        return ret;
    }
};