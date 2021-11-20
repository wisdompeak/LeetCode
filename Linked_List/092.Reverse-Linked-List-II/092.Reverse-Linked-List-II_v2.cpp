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
    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* p = dummy;
        for (int i=0; i<right; i++)
            p = p->next;
        ListNode* c = p->next;
        p->next = NULL;

        p = dummy;
        for (int i=0; i<left-1; i++)
            p = p->next;
        ListNode* b = p->next;
        p->next = NULL;

        b = reverseLinkedList(b);

        p = dummy;
        while (p->next) p = p->next;
        p->next = b;
        while (p->next) p = p->next;
        p->next = c;

        return dummy->next;
    }

    ListNode* reverseLinkedList(ListNode* h)
    {
        ListNode* last = NULL;
        ListNode* cur = h;
        ListNode* nxt;
        while (cur)
        {
            nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        }
        return last;
    }
};
