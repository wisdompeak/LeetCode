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
    ListNode* reverseEvenLengthGroups(ListNode* head) 
    {
        vector<ListNode*>heads;
        vector<int>lens;
                
        ListNode* h = head;
        int len = 1;

        while (1)
        {            
            heads.push_back(h);
            int count = 1;            
            for (int i=0; i<len-1; i++)
            {                
                if (h->next == NULL) break;
                h = h->next;
                count++;
            }
            lens.push_back(count);

            if (h->next==NULL) break;
            ListNode* nxt = h->next;            
            h->next = NULL;
            h = nxt;            
            len++;            
        }
            
        for (int i=0; i<heads.size(); i++)
        {
            if (lens[i]%2==0)
                heads[i] = reverseLinkedList(heads[i]);
        }


        for (int i=0; i<heads.size()-1; i++)
        {
            ListNode* p = heads[i];
            while (p->next!=NULL)
                p = p->next;
            p->next = heads[i+1];
        }

        return heads[0];
    }

    ListNode* reverseLinkedList(ListNode* head)
    {
        ListNode* cur = head;
        ListNode* last = NULL;
        ListNode* next = NULL;
        while (cur!=NULL)
        {
            next = cur->next;
            cur->next = last;
            last = cur;
            cur = next;
        }
        return last;
    }
};
