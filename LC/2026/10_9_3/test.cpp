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
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        auto new_head = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return new_head;
    }

    ListNode *double_(ListNode *l1)
    {
        ListNode dummy;
        auto cur = &dummy;
        int carry = 0;
        while (l1)
        {
            carry += l1->val * 2;
            cur->next = new ListNode(carry % 10);
            carry /= 10;
            cur = cur->next;
            l1 = l1->next;
        }
        if (carry)
        {
            cur->next = new ListNode(carry);
        }
        return dummy.next;
    }

    ListNode *doubleIt(ListNode *head)
    {
        head = reverseList(head);
        auto ret = double_(head);
        return reverseList(ret);
    }
};