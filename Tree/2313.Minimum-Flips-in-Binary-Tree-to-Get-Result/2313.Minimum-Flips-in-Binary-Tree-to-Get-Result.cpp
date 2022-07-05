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
    unordered_map<TreeNode*, unordered_map<int,int>>dp;
public:
    int minimumFlips(TreeNode* root, bool result) 
    {        
        return dfs(root,result);        
    }
    
    int dfs(TreeNode* node, int expected)
    {
        if (!node->left && !node->right)
        {
            return node->val != expected;
        }
        
        if (dp.find(node)!=dp.end() && dp[node].find(expected)!=dp[node].end())
            return dp[node][expected];
        
        int ans = INT_MAX/2;
        if (node->val == 2)
        {            
            if (expected == 1)
            {
                ans = min(ans, dfs(node->left, 1));
                ans = min(ans, dfs(node->right, 1));
            }
            else if (expected == 0)
            {
                ans = min(ans, dfs(node->left, 0) + dfs(node->right, 0));                
            }
        }
        else if (node->val == 3)
        {
            if (expected == 1)
            {
                ans = min(ans, dfs(node->left, 1) + dfs(node->right, 1));                
            }
            else if (expected == 0)
            {
                ans = min(ans, dfs(node->left, 0));
                ans = min(ans, dfs(node->right, 0));
            }
        }
        else if (node->val == 4)
        {
            if (expected == 1)
            {
                ans = min(ans, dfs(node->left, 0) + dfs(node->right, 1));                
                ans = min(ans, dfs(node->left, 1) + dfs(node->right, 0));                
            }
            else if (expected == 0)
            {
                ans = min(ans, dfs(node->left, 0) + dfs(node->right, 0));                
                ans = min(ans, dfs(node->left, 1) + dfs(node->right, 1));                
            }
        }
        else
        {
            TreeNode* child = node->left ? node->left : node->right;
            if (expected == 1)
            {
                ans = min(ans, dfs(child, 0));                                
            }
            else if (expected == 0)
            {
                ans = min(ans, dfs(child, 1));                                
            }
        }
        
        dp[node][expected] = ans;
        return ans;
    }
    
    
};
