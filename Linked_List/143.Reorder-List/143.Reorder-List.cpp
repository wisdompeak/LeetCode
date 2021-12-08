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
    void reorderList(ListNode* head) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* p = dummy;
        int count = 0;
        while (p->next)
        {
            count++;
            p = p->next;
        }

        ListNode* q = dummy;
        for (int i=0; i<(count+1)/2; i++)
            q = q->next;
        ListNode* head2 = q->next;
        q->next = NULL;

        head2 = reverseLinkedList(head2);

        p = head, q = head2;
        ListNode* h = dummy;
        while (p || q)
        {
            if (p)
            {
                h->next = p;
                p = p->next;
                h = h->next;
            }
            if (q)
            {
                h->next = q;
                q = q->next;
                h = h->next;
            }
        }
    }

    ListNode* reverseLinkedList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* last = NULL;
        ListNode* next = NULL;
        while (cur!=NULL)
        {
            next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        return last;
    }
};
