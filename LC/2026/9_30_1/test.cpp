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
        ListNode *p1 = nullptr;
        ListNode *p2 = head;
        while (p2)
        {
            ListNode *p3 = p2->next;
            p2->next = p1;
            p1 = p2;
            p2 = p3;
        }
        return p1;
    }

    ListNode *middleNode(struct ListNode *head)
    {
        ListNode *left = head;
        ListNode *right = head;
        while (right && right->next)
        {
            right = right->next->next;
            left = left->next;
        }
        return left;
    }

    bool isPalindrome(ListNode *head)
    {
        ListNode *mid = middleNode(head);
        ListNode *head2 = reverseList(mid);
        while (head2)
        {
            if (head->val != head2->val)
            {
                return false;
            }

            head = head->next;
            head2 = head2->next;
        }
        return true;
    }
};