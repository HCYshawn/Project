
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        int gcd(int a, int b) 
        {
            while (b != 0) {
                int temp = a % b;
                a = b;
                b = temp;
            }
            return a;
        }
        ListNode* insertGreatestCommonDivisors(ListNode* head) 
        {
            ListNode* ptr = head;
            while(ptr&&ptr->next)
            {
                ListNode* nptr = ptr->next;
                int mid = gcd(ptr->val, nptr->val);
                ListNode* midptr = new ListNode(mid);
    
                ptr->next = midptr;
                midptr->next = nptr;
                ptr = nptr;
            }
            return head;
        }
    };