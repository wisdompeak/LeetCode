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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<TreeNode*>P;
        vector<TreeNode*>Q;
        bool find;
        find = DFS(root,p,P);
        find = DFS(root,q,Q);
        
        int i=P.size()-1;
        int j=Q.size()-1;
        while (i>=0 && j>=0)
        {
            if (P[i]==Q[j])
            {
                i--;
                j--;
            }
            else
                break;
        }
        
        return P[i+1];
        
    }
    
    bool DFS(TreeNode* node, TreeNode* p, vector<TreeNode*>&P)
    {
        if (node==NULL)
            return false;
        
        
        if (node==p || DFS(node->left, p, P) || DFS(node->right, p, P))
        {
            P.push_back(node);
            return true;
        }
        else
            return false;
        
    }
};
