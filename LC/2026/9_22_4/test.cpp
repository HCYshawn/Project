class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        stack<int> st;
        size_t i = 0;
        for (int x : popped)
        {
            while (st.empty() || st.top() != x)
            {
                if (i == pushed.size())
                    return false;
                st.push(pushed[i++]);
            }
            st.pop();
        }
        return true;
    }
};