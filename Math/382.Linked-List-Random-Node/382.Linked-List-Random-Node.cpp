/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    ListNode* root;
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) 
    {
        root=head;
    }
    
    /** Returns a random node's value. */
    int getRandom() 
    {
        ListNode* h=root;
        int count=0;
        int result;
        
        while (h!=NULL)
        {
            if (count==0)
            {
                count++;
                result=h->val;
            }                
            else
            {
                count++;
                int k = rand()%count;
                if (k==0)
                    result = h->val;
            }
            h=h->next;
        }
        return result;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
