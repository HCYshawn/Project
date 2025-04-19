#include <iostream>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ret;
        queue<TreeNode *> q;
        size_t tsize = 0;
        if (root)
        {
            q.push(root);
            tsize = 1;
        }
        while (!q.empty())
        {
            vector<int> v;
            while (tsize--)
            {
                TreeNode *p = q.front();
                q.pop();
                v.push_back(p->val);

                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
            ret.push_back(v);
            tsize = q.size();
        }
        return ret;
    }
};