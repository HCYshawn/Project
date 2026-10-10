/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> ret;
        queue<Node *> q;
        if (root == nullptr)
            return ret;

        q.push(root);
        while (q.size())
        {
            int sz = q.size();
            vector<int> tmp;
            for (int i = 0; i < sz; i++)
            {
                Node *t = q.front();
                q.pop();
                tmp.push_back(t->val);
                for (Node *child : t->children)
                {
                    if (child != nullptr)
                    {
                        q.push(child);
                    }
                }
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};