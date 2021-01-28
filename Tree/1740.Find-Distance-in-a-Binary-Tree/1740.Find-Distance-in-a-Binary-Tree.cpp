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
    int ret = -1;
public:
    int findDistance(TreeNode* root, int p, int q) 
    {
        dfs(root, p, q);        
        return ret;
    }
    
    pair<int,int> dfs(TreeNode* root, int p, int q)
    {
        if (ret!=-1) return {-1,-1};
        if (root==NULL) return {-1, -1};
        
        auto ans1 = dfs(root->left, p, q);
        auto ans2 = dfs(root->right, p, q);
        
        int a = -1, b = -1;
        if (ans1.first!=-1)
            a = ans1.first+1;
        else if (ans2.first!=-1)
            a = ans2.first+1;
        else if (root->val==p)
            a = 0;
        
        if (ans1.second!=-1)
            b = ans1.second+1;
        else if (ans2.second!=-1)
            b = ans2.second+1;
        else if (root->val==q)
            b = 0;
        
        if (ret==-1 && a!=-1 && b!=-1)
        {
            ret = a+b;
        }
        return {a,b};
    }
};
