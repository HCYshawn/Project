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
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return nullptr;

        ListNode *left = head;
        ListNode *right = head;
        ListNode* pre = nullptr;
        while(right&&right->next)
        {
            right = right->next->next;
            pre = left;
            left = left->next;
        }
        
            pre->next = left->next;

        return head;
    }
};