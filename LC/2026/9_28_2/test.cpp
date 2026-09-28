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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *p = list1;
        int count = 0;
        while (list1)
        {
            if (count == a - 1)
            {
                int t = count;
                ListNode *tmp1 = p;
                while (t <= b && tmp1->next != nullptr)
                {
                    t++;
                    tmp1 = tmp1->next;
                }
                p->next = list2;
                ListNode *tmp2 = list2;
                while (tmp2->next != nullptr)
                {
                    tmp2 = tmp2->next;
                }
                tmp2->next = tmp1;
                break;
            }
            else
            {
                p = p->next;
                count++;
            }
        }
        return list1;
    }
};