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
    int maxDepth = 0;
    int deepCount = 0;
    TreeNode* ret = NULL;
    unordered_map<int,int>Map;
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {        
        dfs(root, 1);    
        for (auto x:Map)
            deepCount += (x.second == maxDepth);
        dfs2(root);
        return ret;
    }

    void dfs(TreeNode* node, int depth)
    {
        if (node==NULL) return;
        Map[node->val] = depth;
        maxDepth = max(maxDepth, depth);
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }

    int dfs2(TreeNode* node)
    {
        if (node==NULL) return 0;
        int self = (Map[node->val]==maxDepth);
        int a = dfs2(node->left);
        int b = dfs2(node->right);
        if (self+a+b == deepCount && ret==NULL)
            ret = node;
        return self+a+b;
    }
};
