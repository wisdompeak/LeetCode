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
        vector<TreeNode*>path1 = dfs(root, p);
        reverse(path1.begin(), path1.end());

        vector<TreeNode*>path2 = dfs(root, q); 
        reverse(path2.begin(), path2.end());
        
        if (path1.size()==0 ||path2.size()==0)
            return NULL;
        
        int i=0;
        while (i<path1.size() && i<path2.size() && path1[i]==path2[i])
            i++;
        return path1[i-1];        
            
    }
    
    vector<TreeNode*>dfs(TreeNode* root, TreeNode* p)
    {
        if (root==NULL) return {};
        if (root==p) return {root};
        vector<TreeNode*>path = dfs(root->left, p);
        if (!path.empty())
        {
            path.push_back(root);
            return path;
        }
        path.clear();
        path = dfs(root->right, p);
        if (!path.empty())
        {
            path.push_back(root);
            return path;
        }
        return {};
    }
};
