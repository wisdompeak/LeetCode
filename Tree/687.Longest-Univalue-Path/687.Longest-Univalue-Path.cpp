/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int ret = 0;
public:
    int longestUnivaluePath(TreeNode* root) 
    {
        dfs(root);
        return max(0, ret-1);
    }
    int dfs(TreeNode* node)
    {
        if (node==NULL) return 0;        
        int len1 = dfs(node->left);
        int len2 = dfs(node->right);
        
        int L = 0, R = 0;
        if (node->left && node->left->val == node->val)
            L = len1;
        if (node->right && node->right->val == node->val)
            R = len2;
        ret = max(ret, L+1+R);
        return 1+max(L,R);
    }
};
