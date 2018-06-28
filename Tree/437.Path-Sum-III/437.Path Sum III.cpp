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
    int count=0;
    
public:
    int pathSum(TreeNode* root, int sum) 
    {
        GoThrough(root,sum);
        return count;
    }
    
    void GoThrough(TreeNode *root,int sum)
    {
        if (root==NULL) return;
        
        GoThrough(root->left,sum);        
        GoThrough(root->right,sum);
        count+= pathSumNum(root,sum);        
    }
    
    int pathSumNum(TreeNode* node, int sum)
    {
        if (node==NULL) return 0;
        if (node->val==sum) 
            return 1+pathSumNum(node->left,0)+pathSumNum(node->right,0);
        else
            return pathSumNum(node->left,sum-node->val)+pathSumNum(node->right,sum-node->val);
    }
};
