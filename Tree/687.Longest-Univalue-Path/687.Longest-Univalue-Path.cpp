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
    int longestUnivaluePath(TreeNode* root) 
    {
        int temp = DFS(root);
        return max(0,result-1);
    }
    
    int DFS(TreeNode* root)
    {
        if (root==NULL) return 0;
        int L = DFS(root->left);
        int R = DFS(root->right);

        int LL=0;
        int RR=0;
        if (root->left!=NULL && root->left->val==root->val)
            LL = L;
        if (root->right!=NULL && root->right->val==root->val)
            RR = R;
        result = max(result, LL+RR+1);
        return max(LL+1,RR+1);        
    }
};
