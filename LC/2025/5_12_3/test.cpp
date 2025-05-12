#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList
{
private:
    ListNode *head;
    int size;

public:
    MyLinkedList()
    {
        this->head = new ListNode(0);
        this->size = 0;
    }

    int get(int index)
    {
        if (index < 0 || index >= size)
            return -1;
        ListNode *ptr = head;
        for (int i = 0; i <= index; i++)
        {
            ptr = ptr->next;
        }
        return ptr->val;
    }

    void addAtHead(int val)
    {
        addAtIndex(0, val);
    }

    void addAtTail(int val)
    {
        addAtIndex(size, val);
    }

    void addAtIndex(int index, int val)
    {
        if (index > size)
            return;
        index = max(0, index);
        ListNode *ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        ListNode *mid = new ListNode(val);
        mid->next = ptr->next;
        ptr->next = mid;
        size++;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= size)
            return;
        ListNode *ptr = head;
        for (int i = 0; i < index; i++)
        {
            ptr = ptr->next;
        }
        ListNode *del = ptr->next;
        ptr->next = del->next;
        delete del;
        size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */