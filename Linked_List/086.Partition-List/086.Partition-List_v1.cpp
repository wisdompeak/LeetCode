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
        ListNode* h1 = new ListNode(0);
        ListNode* h2 = new ListNode(0);
        ListNode* p = h1;
        ListNode* q = h2;

        while (head!=NULL)
        {
            if (head->val<x)
            {
                p->next = head;                
                p = p->next;
            }
            else
            {
                q->next= head;
                q = q->next;
            }
            head = head->next;
        }
        p->next = h2->next;
        q->next = NULL;
        return h1->next;        
    }
};
