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
    TreeNode* ret = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        int a = dfs(root, p, q);
        return ret;      
    }
    
    int dfs(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root==NULL) return 0;
        int left = dfs(root->left, p, q);
        int right = dfs(root->right, p, q);
        int self = (root==p || root==q);
        int count = left+right+self;
        if (count==2 && ret==NULL)
            ret = root;
        return count;
    }
};
