/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
        ListNode* pre1=new ListNode(0);
        ListNode* pre2=new ListNode(0);
        
        ListNode* h=head;
        ListNode* p=pre1;
        ListNode* q=pre2;
        
        while (h!=NULL)
        {
            if (h->val<x)
            {
                p->next=h;
                h=h->next;
                p=p->next;
            }   
            else
            {
                q->next=h;
                h=h->next;
                q=q->next;
            }
        }
        
        q->next=NULL;
        
        p->next=pre2->next;
        
        return pre1->next;
        
    }
};
