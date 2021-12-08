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
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        for(; fast && fast->next; slow = slow->next, fast = fast->next->next);
        ListNode *head1 = head;
        ListNode *head2 = slow->next;
        slow->next = nullptr;

        // reverse list2
        ListNode *nextNode = nullptr;
        for(ListNode *cur = head2; cur != nullptr;) {
            ListNode *curNext = cur->next;
            cur->next = nextNode;
            nextNode = cur;
            cur = curNext;
        }
        head2 = nextNode;

        // traverse list1 to insert
        for(ListNode *ptr1 = head1, *ptr2 = head2; ptr1 && ptr2;) {
            ListNode *ptr1Next = ptr1->next, *ptr2Next = ptr2->next;
            ptr1->next = ptr2;
            ptr2->next = ptr1Next;
            ptr1 = ptr1Next;
            ptr2 = ptr2Next;
        }
    }
};
