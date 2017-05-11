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
    int result;
public:
    int longestConsecutive(TreeNode* root) 
    {
        result=0;
        int x=DFS(root);
        return result;
    }
    
    int DFS(TreeNode* root)
    {
        if (root==NULL) return 0;
        
        int res=1;
        if (root->left!=NULL)
        {
            int temp = DFS(root->left);
            if (root->left->val == root->val+1)
                res = max(res, temp+1);
        }
        
        if (root->right!=NULL)
        {
            int temp = DFS(root->right);
            if (root->right->val == root->val+1)
                res = max(res, temp+1);
        }
        
        result = max(res,result);
        return res;
        
    }
};
