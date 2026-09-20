class Solution
{
public:
    int calPoints(vector<string> &operations)
    {
        int ret = 0;
        stack<int> tmp;
        for (int i = 0; i < operations.size(); i++)
        {
            if (operations[i] == "+")
            {
                int x = tmp.top();
                tmp.pop();
                int y = tmp.top();
                tmp.push(x);
                tmp.push(x + y);
            }
            else if (operations[i] == "D")
            {
                int x = tmp.top();
                tmp.push(2 * x);
            }
            else if (operations[i] == "C")
            {
                tmp.pop();
            }
            else
            {
                tmp.push(stoi(operations[i]));
            }
        }
        while (!tmp.empty())
        {
            ret += tmp.top();
            tmp.pop();
        }
        return ret;
    }
};