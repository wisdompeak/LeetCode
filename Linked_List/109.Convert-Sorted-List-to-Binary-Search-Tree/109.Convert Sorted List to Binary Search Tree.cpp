/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) 
    {
        if (head==NULL) return NULL;
        
        if (head->next==NULL)
        {
            TreeNode* root = new TreeNode(head->val);
            return root;
        }
        
        if (head->next->next==NULL)
        {
            TreeNode* root = new TreeNode(head->val);
            root->right = new TreeNode(head->next->val);
            return root;
        }
        
        ListNode* fast=head;
        ListNode* slow=head;
        ListNode* temp;
        while (fast->next!=NULL && fast->next->next!=NULL)
        {
            fast=fast->next->next;
            temp=slow;
            slow=slow->next;
        }
        temp->next=NULL;
        
        TreeNode* root=new TreeNode(slow->val);
        root->left=sortedListToBST(head);
        root->right=sortedListToBST(slow->next);
        
        return root;
        
    }
};
