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
    ListNode* reverseList(ListNode* head) 
    {
        return helper(NULL, head);
    }
    
    ListNode* helper(ListNode*last, ListNode* head)
    {
        if (head==NULL) return last;
        ListNode* nxt = head->next;
        head->next = last;
        return helper(head, nxt);
    }
};
