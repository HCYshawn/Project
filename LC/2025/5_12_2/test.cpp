

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
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr)
            return head;
        ListNode *p1 = head->next;
        ListNode *p2 = head;
        ListNode *p3 = p1;
        while (p3 != nullptr && p3->next != nullptr)
        {
            p2->next = p3->next;
            p2 = p2->next;
            p3->next = p2->next;
            p3 = p3->next;
        }
        p2->next = p1;
        return head;
    }
};