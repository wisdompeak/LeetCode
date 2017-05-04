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
    bool isBalanced(TreeNode* root) 
    {
        if (depth(root)==-1)
            return false;
        else
            return true;
    }
    
    int depth(TreeNode* node)
    {
        if (node==NULL) return 0;
        
        int d1=depth(node->left);
        int d2=depth(node->right);
        if (d1==-1 || d2==-1 || abs(d1-d2)>1) 
            return -1;
        else
            return max(d1,d2)+1;
    }
};
