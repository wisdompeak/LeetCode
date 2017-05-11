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
    TreeNode* last;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        last=NULL;
        TreeNode* result = DFS(root,p);
        return result;
    }
    
    TreeNode* DFS(TreeNode* root, TreeNode* p)
    {
        if (root==NULL) return NULL;
        
        TreeNode* temp;
        
        temp = DFS(root->left,p);
        if (temp!=NULL) return temp;
        
        if (last==p) 
            return root;
        else
            last=root;
        
        temp = DFS(root->right,p);
        if (temp!=NULL) return temp;
        
        return NULL;        
    }
};
