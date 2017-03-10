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
    ListNode *detectCycle(ListNode *head) 
    {
        if (head==NULL) return NULL;
        
        ListNode* slow=head;
        ListNode* fast=head;
        int flag=0;
        
        while (fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
            
            if (fast==slow) 
            {
                flag=1;
                break;
            }
        }
        
        if (flag==0) return NULL;
        
        fast=head;
        while (fast!=slow)
        {
            fast=fast->next;
            slow=slow->next;
        }
        
        return fast;
        
    }
};
