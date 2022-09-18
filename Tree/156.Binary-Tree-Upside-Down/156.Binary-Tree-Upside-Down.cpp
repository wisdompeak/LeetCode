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
    TreeNode* upsideDownBinaryTree(TreeNode* root) 
    {
        if (root==NULL) return NULL;
        if (root->left==NULL && root->right==NULL) return root;
        
        TreeNode* head = upsideDownBinaryTree(root->left);
        TreeNode* node = head;
        
        while (node->right!=NULL)
            node=node->right;
        
        node->left = root->right;
        node->right = root;
        root->left=NULL;
        root->right=NULL;
        
        return head;
    }
};
