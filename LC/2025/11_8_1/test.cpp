class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ret;
        stack<char> st;
        for (auto c : s)
        {
            if (c == ')')
                st.pop();
            if (!st.empty())
                ret.push_back(c);
            if (c == '(')
                st.emplace(c);
        }
        return ret;
    }
};