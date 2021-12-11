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
    int count = 0;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        TreeNode* ret = lca(root, p, q);
        if (count!=2) return NULL;
        else return ret;        
    }
    
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root==NULL) return NULL;
        
        TreeNode* L = lca(root->left,p,q);
        TreeNode* R = lca(root->right,p,q);
        
        if (root==p || root==q)
        {
            count++;
            return root;
        }
        
        if (L&&R)
            return root;
        else if (!L&&R)
            return R;
        else if (L&&!R)
            return L;
        else
            return NULL;
    }
};
