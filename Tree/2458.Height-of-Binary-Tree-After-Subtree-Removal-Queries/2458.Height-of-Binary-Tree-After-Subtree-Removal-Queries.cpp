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
    unordered_map<int,vector<int>>d2h;
    int depth[100005];
    int height[100005];
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        dfs_height(root, 0);
        for (auto& [d, hs] : d2h)
            sort(hs.rbegin(), hs.rend());

        vector<int>rets;
        for (int node: queries)
        {
            int d = depth[node];
            int h = height[node];
            if (d2h[d].size()==1)
                rets.push_back(d - 1);
            else if (d2h[d][0] == h)
                rets.push_back(d2h[d][1] + d);
            else
                rets.push_back(d2h[d][0] + d);
        }
        return rets;

    }

    int dfs_height(TreeNode* node, int d)
    {        
        if (node==NULL) return -1;
        int h = max(dfs_height(node->left, d+1), dfs_height(node->right, d+1)) + 1;
        d2h[d].push_back(h);        
        depth[node->val] = d;
        height[node->val] = h;
        return h;
    }
};
