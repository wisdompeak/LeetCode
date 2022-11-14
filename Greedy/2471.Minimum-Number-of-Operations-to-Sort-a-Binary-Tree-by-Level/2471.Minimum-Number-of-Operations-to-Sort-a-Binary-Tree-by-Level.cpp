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
    vector<int>level[100005];
    int maxDepth = 0;
public:
    int minimumOperations(TreeNode* root) 
    {
        dfs(root, 0);
        int count = 0;
        for (int t=0; t<=maxDepth; t++)
        {            
            auto sorted = level[t];
            sort(sorted.begin(), sorted.end());
            unordered_map<int,int>rank;
            for (int i=0; i<sorted.size(); i++)
                rank[sorted[i]] = i;
                        
            int n = level[t].size();
            for (int i=0; i<n; i++)
            {
                while (rank[level[t][i]] != i)
                {
                    swap(level[t][i], level[t][rank[level[t][i]]]);
                    count++;
                }                    
            }            
        }
        return count;
    }
    
    void dfs(TreeNode* node, int depth)
    {
        if (node==NULL) return;
        maxDepth = max(maxDepth, depth);
        level[depth].push_back(node->val);
        dfs(node->left, depth+1);
        dfs(node->right, depth+1);
    }
};
