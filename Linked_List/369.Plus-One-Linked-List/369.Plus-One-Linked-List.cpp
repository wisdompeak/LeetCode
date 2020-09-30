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
    ListNode* plusOne(ListNode* head) 
    {
        int carry = 0;
        dfs(head, carry);
        if (carry == 0)
            return head;
        else
        {
            ListNode* node = new ListNode(1);
            node->next = head;
            return node;
        }
    }
    
    void dfs(ListNode* head, int& carry) 
    {       
        if (head==NULL)
        {
            carry = 1;
            return;
        }
        
        dfs(head->next, carry);
        
        int val = head->val + carry;
        carry = val / 10;
        head->val = val % 10;        
        
        // if (head->val==3) cout<<val<<endl;
    }
};
