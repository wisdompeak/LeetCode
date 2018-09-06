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
        if (s==NULL||t==NULL)
            return (s==t);
        if (isSame(s,t))
            return true;
        else
            return isSubtree(s->left,t) || isSubtree(s->right,t);
    }
    
    bool isSame(TreeNode* a, TreeNode* b)
    {
        if (a==NULL || b==NULL) return a==b;
        if (a->val!=b->val) return false;
        return isSame(a->left,b->left) && isSame(a->right,b->right);
    }
};
