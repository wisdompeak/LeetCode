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
    TreeNode* CurMax = new TreeNode(INT_MIN);
    TreeNode* first = NULL;
    TreeNode* second = NULL;

public:
    void recoverTree(TreeNode* root) 
    {
       DFS(root);
       
       int temp = first->val;
       first->val = second->val;
       second->val = temp;
    }
    
    void DFS(TreeNode* node)
    {
        if (node==NULL) return;
        
        DFS(node->left);
        
        if (node->val >= CurMax->val)
            CurMax = node;
        else
        {
            if (first==NULL) 
            {
                first=CurMax;
                second=node;
                CurMax=node;
            }
            else
                second=node;
        }
        
        DFS(node->right);
            
    }
    
};
