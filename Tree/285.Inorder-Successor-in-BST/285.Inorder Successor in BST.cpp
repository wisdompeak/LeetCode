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
    TreeNode* lastRead=NULL;
    TreeNode* result=NULL;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) 
    {
        bool flag = DFS(root,p);
        return result;
    }
    
    bool DFS(TreeNode* node, TreeNode* p)
    {
        if (node==NULL) return false;
        
        if (DFS(node->left,p)) return true;
        
        if (lastRead==p)
        {
            result=node;
            return true;
        }
        lastRead=node;
        
        if (DFS(node->right,p)) return true;
        
        return false;
        
    }
};
