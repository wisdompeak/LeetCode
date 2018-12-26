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
    bool isCompleteTree(TreeNode* root) 
    {
        int nodeNums = countNodes(root);
        return DFS(root,0,nodeNums);
    }
    
    bool DFS(TreeNode* node, int index, int nodeNums)
    {
        if (!node) return true;
        if (index>=nodeNums) return false;
        return DFS(node->left,index*2+1,nodeNums)&&DFS(node->right,index*2+2,nodeNums);
    }
    
    int countNodes(TreeNode* node)
    {
        if (!node) return 0;
        else return 1+countNodes(node->left)+countNodes(node->right);
    }
};
