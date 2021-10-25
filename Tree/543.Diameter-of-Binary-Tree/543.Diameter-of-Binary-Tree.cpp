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
    int diameterOfBinaryTree(TreeNode* root) 
    {
        LongestPathToLeaf(root); 
        return ret-1;
    }
    
    int LongestPathToLeaf(TreeNode* node)
    {
        if (node == NULL) return 0;
        
        int leftPath = LongestPathToLeaf(node->left);
        int rightPath = LongestPathToLeaf(node->right);
        ret = max(ret, leftPath+1+rightPath);
        return max(leftPath, rightPath) + 1;
    }
};
