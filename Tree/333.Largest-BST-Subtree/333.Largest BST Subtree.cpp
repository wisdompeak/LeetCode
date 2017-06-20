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
    int result=0;
    
public:
    int largestBSTSubtree(TreeNode* root) 
    {
        int x = isBST(root);
        return result;
    }
    
    int isBST(TreeNode* root) 
    {
        if (root==NULL) return 0;
        
        int flag=1;
        
        if (root->left!=NULL)
        {
            TreeNode* node=root->left;
            while (node->right!=NULL) node=node->right;
            if (node->val>=root->val)
                flag=0;
        }
        
        if (root->right!=NULL)
        {
            TreeNode* node=root->right;
            while (node->left!=NULL) node=node->left;
            if (node->val<=root->val)
                flag=0;
        }        
        
        int leftNum = isBST(root->left);
        int rightNum = isBST(root->right);
        
        if (flag==0 || leftNum==-1 || rightNum==-1) return -1;
        
        result=max(result,leftNum+rightNum+1);
        
        return leftNum+rightNum+1;
        
    }
};
