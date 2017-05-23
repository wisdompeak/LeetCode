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
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        if (sameTree(s,t)) return true;
        return s->left!=NULL && isSubtree(s->left,t)||s->right!=NULL && isSubtree(s->right,t);
    }
    
    bool sameTree(TreeNode*s, TreeNode* t)
    {
        if (s==NULL || t==NULL) return (s==t);
        if (s->val==t->val)
            return sameTree(s->left,t->left)&&sameTree(s->right,t->right);
        else
            return false;
    }
};
