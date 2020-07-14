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
    ListNode* deleteNodes(ListNode* head, int m, int n) 
    {
        ListNode* p = head;
        while (p)
        {
            for (int i=0; i<m-1; i++)
            {
                p = p->next;
                if (!p) break;
            }
            
            if (!p) break;
            
            ListNode* q = p;            
            for (int i=0; i<n; i++)
            {
                q = q->next;
                if (!q) break;
            }
            if (!q)
            {
                p->next = NULL;
                break;
            }
            else
            {
                p->next = q->next;
                p = p->next;                
            }
        }
        
        return head;
        
    }
};
