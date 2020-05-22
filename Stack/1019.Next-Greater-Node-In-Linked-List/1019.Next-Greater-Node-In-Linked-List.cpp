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
    vector<int> nextLargerNodes(ListNode* head) 
    {
        vector<int>ret;
        stack<pair<int,int>>Stack;
        ListNode* p = head;
        int i = 0;

        while (p!=NULL)
        {
            while (!Stack.empty() && Stack.top().first < p->val)
            {
                ret[Stack.top().second] = p->val;
                Stack.pop();
            }
            ret.push_back({0});
            Stack.push({p->val, i});
            i++;
            p = p->next;
        }

        return ret;
    }
};
