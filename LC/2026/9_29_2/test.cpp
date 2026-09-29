/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        int n = 0;
        for (ListNode *cur = head; cur; cur = cur->next)
        {
            n++;
        }

        ListNode dummy(0, head);
        ListNode *last_tail = &dummy;

        for (; n >= k; n -= k)
        {
            ListNode *pre = nullptr;
            ListNode *cur = last_tail->next;
            for (int i = 0; i < k; i++)
            {
                ListNode *nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }

            ListNode *tail = last_tail->next;
            tail->next = cur;
            last_tail->next = pre;
            last_tail = tail;
        }
        return dummy.next;
    }
};