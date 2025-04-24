

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode nhead(0, head);
        auto mid = &nhead;
        while (mid->next)
        {
            auto net = mid->next;
            if (net->val == val)
            {
                mid->next = net->next;
                delete net;
            }
            else
            {
                mid = net;
            }
        }
        return nhead.next;
    }
};