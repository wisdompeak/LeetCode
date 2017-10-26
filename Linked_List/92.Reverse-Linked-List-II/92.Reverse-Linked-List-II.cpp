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
    void reorderList(ListNode* head) 
    {
        if (head==NULL || head->next==NULL)
            return;
        
        ListNode* h=new ListNode(0);
        h->next=head;
        
        ListNode* p=h;
        int count=0;
        while (p->next!=NULL)
        {
            p=p->next;
            count++;
        }        
        p=h;
        for (int i=0; i<(count-count/2); i++)
            p=p->next;       
                                      
        ListNode* temp=p->next;
        p->next=NULL;
        p=temp;
        ListNode* q=NULL;
        while (p!=NULL)
        {
            ListNode* temp=p->next;
            p->next=q;
            q=p;
            p=temp;
        }
        
        p=head;        
        while (p!=NULL || q!=NULL)
        {
            if (p!=NULL)
            {
                h->next=p;
                h=h->next;
                p=p->next;
            }
            if (q!=NULL)
            {
                h->next=q;
                h=h->next;
                q=q->next;
            }
        }        
    }
};
