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
        ListNode* p=new ListNode(0);
        ListNode* q=new ListNode(0);
        ListNode* h1=p;
        ListNode* h2=q;
        
        while (head!=NULL)
        {
            if (head->val<x)
            {
                p->next=new ListNode(head->val);
                p=p->next;
            }
            else
            {
                q->next=new ListNode(head->val);
                q=q->next;
            }            
            head=head->next;
        }
        
        p->next=h2->next;
        
        return h1->next;
        
    }
};
