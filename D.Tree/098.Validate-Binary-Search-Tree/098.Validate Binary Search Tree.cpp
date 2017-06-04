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
    vector<int>q;
public:
    bool isValidBST(TreeNode* root) 
    {
        if (root==NULL) return true;

        if (isValidBST(root->left)==false) 
            return false;

        q.push_back(root->val);
        if (q.size()>1 && q.back()<=q[q.size()-2])
            return false;

        if (isValidBST(root->right)==false) 
            return false;

        return true;
    }
};
