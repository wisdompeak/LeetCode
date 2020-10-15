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
        if (head==0) return NULL;
        ListNode* end = head;
        int count = 1;        
        while (end->next != NULL)
        {
            count++;
            end = end->next;
        }
        int t = count - k % count - 1;

        ListNode* p = head;
        for (int i=0; i<t; i++)
            p = p->next;
        end->next = head;
        ListNode* ret = p->next;
        p->next = NULL;
        return ret;        
    }
};
