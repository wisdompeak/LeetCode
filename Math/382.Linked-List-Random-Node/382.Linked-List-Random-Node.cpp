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
    ListNode* node;
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        node = head;
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        ListNode* h = node;
        int k = 0;
        int x = 0;
        
        while (h!=NULL)
        {
            k++;
            int r = rand()%k;
            if (r==0)
                x = h->val;
            h = h->next;
        }
        
        return x;
    }
};
