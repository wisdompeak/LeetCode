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
    ListNode* sortLinkedList(ListNode* head) 
    {

        ListNode* pos = new ListNode(0);
        ListNode* neg = new ListNode(0);
        ListNode* h = head;
        ListNode* p1 = pos;
        ListNode* p2 = neg;
        
        while (h)
        {
            if (h->val>=0)
            {
                p1->next = h;
                h = h->next;
                p1 = p1->next;
                                                
            }
            else
            {
                p2->next = h;
                h = h->next;
                p2 = p2->next;              
            }
        }
        p1->next = NULL;
        p2->next = NULL;
        
        pos = pos->next;
        neg = neg->next;
        
        neg = reverseLinkedList(neg);
        
        if (neg)
        {
            h = neg;
            while (h->next) h = h->next;
            h->next = pos;            
            return neg;
        }
        else
            return pos;
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
