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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        ListNode* dummy = new ListNode();
        dummy -> next = head;
        ListNode* h = dummy;
        while (h && h->next)
        {
            ListNode* p = h->next; 
            int count = 1;           
            while (p && p->next && p->next->val == p->val)
            {
                count++;
                p = p->next;
            }                
            if (count > 1)
                h->next = p->next;
            else
                h = h->next;
        }
        return dummy->next;
    }
};
