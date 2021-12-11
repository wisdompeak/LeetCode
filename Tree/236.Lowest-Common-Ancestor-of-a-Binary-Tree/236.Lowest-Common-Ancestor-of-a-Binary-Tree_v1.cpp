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
        bool temp;
        temp = DFS(root,p,P);
        temp = DFS(root,q,Q);
        
        TreeNode* result;
        int i=P.size()-1;
        int j=Q.size()-1;
        while (i>=0 && j>=0 && P[i]==Q[j])
        {
            result=P[i];
            i--;
            j--;
        }
        return result;
    }
    
    bool DFS(TreeNode* root, TreeNode* r, vector<TreeNode*>& R)
    {
        if (root==NULL) return false;
        if (root==r || DFS(root->left,r,R) || DFS(root->right,r,R)) 
        {
            R.push_back(root);
            return true;
        }
        else
            return false;
    }
};
