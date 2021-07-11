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
    unordered_map<int,TreeNode*>val2root;
    unordered_set<int>nodeVals;
    unordered_set<int>visited;
public:
    void checkNodes(TreeNode* node)
    {
        if (node==NULL) return;
        nodeVals.insert(node->val);
        checkNodes(node->left);
        checkNodes(node->right);
    }

    TreeNode* canMerge(vector<TreeNode*>& trees) 
    {
        int n = trees.size();        
        for (int i=0; i<n; i++)
        {
            val2root[trees[i]->val] = trees[i];
            checkNodes(trees[i]->left);
            checkNodes(trees[i]->right);
        }
        
        int count = 0;
        TreeNode* root;
        for (int i=0; i<n; i++)
        {
            if (nodeVals.find(trees[i]->val)==nodeVals.end())
            {
                root = trees[i];
                count++;
            }                
        }
        if (count != 1) return NULL;

        visited.insert(root->val);
        bool ok = dfs(root, INT_MIN, INT_MAX);
        if (ok && visited.size()==n)
            return root;
        else
            return NULL;
    }

    bool dfs(TreeNode*& node, int mn, int mx)
    {
        if (node==NULL) return true;
        if (node->val < mn || node->val > mx) return false;
        int val = node->val;
        if (node->left || node->right)
        {
            return dfs(node->left, mn, val - 1) && dfs(node->right, val+1, mx);
        }
        else if (val2root.find(val)!=val2root.end())
        {
            node = val2root[val];
            visited.insert(val);
            return dfs(node->left, mn, val - 1) && dfs(node->right, val+1, mx);
        }
        return true;
    }
};
