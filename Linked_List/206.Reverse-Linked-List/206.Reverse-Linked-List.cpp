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
        ListNode* last = NULL;
        ListNode* cur = head;
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
