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
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;

        for (int i=1; i<=m-1; i++)
            cur = cur->next;

        ListNode* end_of_fisrt = cur;
        cur = cur->next;

        ListNode* start_of_second = cur;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        for (int i=m; i<=n; i++)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        end_of_fisrt->next = prev;
        start_of_second->next = cur;
        return dummy->next;
    }

};
