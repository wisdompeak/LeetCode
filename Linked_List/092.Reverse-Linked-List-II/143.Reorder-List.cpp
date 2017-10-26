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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next=head;
        
        ListNode* p=dummyHead;
        for (int i=1; i<=m-1; i++)
            p=p->next;
        ListNode* end_of_first=p;
        p=p->next;
        
        ListNode* last=p;
        ListNode* front = NULL;
        for (int i=m; i<=n; i++)
        {
            ListNode* temp = p->next;
            p->next=front;
            front=p;
            p=temp;
        }
        
        end_of_first->next=front;
        last->next = p;
        
        return dummyHead->next;
            

    }
};
