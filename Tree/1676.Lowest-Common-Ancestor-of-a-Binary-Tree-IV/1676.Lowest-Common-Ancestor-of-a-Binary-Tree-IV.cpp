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
    unordered_set<TreeNode*>Set;
    TreeNode* ret = NULL;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) 
    {
        for (auto x: nodes)
            Set.insert(x);
        
        dfs(root);
        return ret;        
    }
    
    int dfs(TreeNode* node)
    {
        if (node==NULL) return 0;
        int left = dfs(node->left);
        int right = dfs(node->right);
        int self = Set.find(node)!=Set.end();
        if (left+right+self==Set.size() && ret==NULL)
            ret = node;
        return left+right+self;
    }
};
