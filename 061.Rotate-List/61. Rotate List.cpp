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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        ListNode* pre=new ListNode(0);
        pre->next=head;
        ListNode* end=pre;
        
        int Len=0;
        while (end->next!=NULL)
        {
            end=end->next;
            Len++;
        }
        
        if (Len<=1) return head;

        k=k%Len;
        if (k==0) return head;

        ListNode* p = pre;
        ListNode* q = pre;
        for (int i=0; i<k; i++)
            p=p->next;
            
        while (p->next!=NULL)
        {
            p=p->next;
            q=q->next;
        }
        
        ListNode* NewHead=q->next;
        q->next=NULL;
        end->next=head;
        
        return NewHead;
        
    }
};
