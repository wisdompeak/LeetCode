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
    void flatten(TreeNode* root) 
    {
        if (root==NULL) return;
        
        if (root->left!=NULL)
        {
            flatten(root->left);
            flatten(root->right);
            
            TreeNode* node = root->left;
            while (node->right!=NULL)
                node=node->right;
            
            node->right = root->right;
            root->right = root->left;
            root->left = NULL;
            
        }
        else
        {
            flatten(root->right);
        }
            
    }
    
};
