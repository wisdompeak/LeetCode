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
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        vector<ListNode*>heads;        
        ListNode* p = head;

        int flag = 1;
        while (p)
        {
            heads.push_back(p);
            
            for (int i=0; i<k-1; i++)            
            {
                if (p->next) p = p->next;
                else flag = 0;
            }
                
            ListNode* nxt = p->next;
            p->next = NULL;
            p = nxt;
        }

        for (int i=0; i<heads.size(); i++)
        {
            if (flag!=0 || i!=heads.size()-1)
                heads[i] = reverseLinkedList(heads[i]);
        }

        for (int i=0; i<heads.size()-1; i++)
        {
            ListNode* h = heads[i];
            while (h->next) h = h->next;
            h->next = heads[i+1];
        }

        return heads[0];        
    }

    ListNode* reverseLinkedList(ListNode* h)
    {
        ListNode* last = NULL;
        ListNode* cur = h;
        ListNode* nxt;
        while (cur)
        {
            nxt = cur->next;
            cur->next = last;
            last = cur;
            cur = nxt;
        }
        return last;
    }    
};
