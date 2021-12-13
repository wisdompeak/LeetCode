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
        dfs(root, p, q);
        return ret;
    }
    
    int dfs(TreeNode* node, TreeNode* p, TreeNode* q) 
    {
        if (node==NULL) return 0;
        int count = dfs(node->left, p, q) + dfs(node->right, p, q);
        if (node==p || node==q) count++;        
        if (count == 2 && ret == NULL)
            ret = node;
        return count;        
    }
};
