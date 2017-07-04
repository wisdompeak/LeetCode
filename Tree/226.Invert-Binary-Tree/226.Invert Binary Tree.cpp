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
    TreeNode* invertTree(TreeNode* root) 
    {
        if (root==NULL) return NULL;
        TreeNode* temp=invertTree(root->right);
        root->right=invertTree(root->left);
        root->left=temp;
        return root;
    }
};
