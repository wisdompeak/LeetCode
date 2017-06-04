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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        if (root==NULL) return 0;
        int temp = LongestPathToLeaf(root);
        return result-1;
    }
    
    int LongestPathToLeaf(TreeNode* root)
    {
        if (root==NULL) return 0;
        
        int left = LongestPathToLeaf(root->left);
        int right = LongestPathToLeaf(root->right);
        result = max(result,left+right+1);
        return max(left,right)+1;
    }
};
