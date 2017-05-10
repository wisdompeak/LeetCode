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
        
        if (root->left==NULL) 
            return root;
        else
        {
            TreeNode* nextRoot = root->left;
            TreeNode* nextRootAlien = new TreeNode(root->left->val);
            nextRootAlien->right = root;
            nextRootAlien->left = root->right;
            root->left=NULL;
            root->right=NULL;
            return DFS(nextRoot,nextRootAlien);
        }
    }
    
    TreeNode* DFS(TreeNode* root, TreeNode* rootAlien)
    {
        if (root->left==NULL) 
            return rootAlien;
        else
        {
            TreeNode* nextRoot = root->left;
            TreeNode* nextRootAlien = new TreeNode(root->left->val);
            nextRootAlien->right = rootAlien;
            nextRootAlien->left = root->right;
            return DFS(nextRoot,nextRootAlien);
        }
        
    }
};
