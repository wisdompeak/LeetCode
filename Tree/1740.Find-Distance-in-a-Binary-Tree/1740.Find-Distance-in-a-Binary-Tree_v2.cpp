/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int lcaDepth = -1, pDepth, qDepth;
    TreeNode* lcaNode;
    int lowestCommonAncestor(TreeNode* root, int p, int q, int depth) {
        if(!root) return 0;

        int count = lowestCommonAncestor(root->left, p, q, depth + 1) + 
                    lowestCommonAncestor(root->right, p, q, depth + 1) +
                    (root->val == p) + (root->val == q);

        if(root->val == p) pDepth = depth; 
        if(root->val == q) qDepth = depth;
        if(count == 2 && lcaDepth == -1) lcaDepth = depth;
        
        return count;
    }
public:
    int findDistance(TreeNode* root, int p, int q) {
        lowestCommonAncestor(root, p, q, 0);

        return (pDepth - lcaDepth) + (qDepth - lcaDepth);
    }
};
