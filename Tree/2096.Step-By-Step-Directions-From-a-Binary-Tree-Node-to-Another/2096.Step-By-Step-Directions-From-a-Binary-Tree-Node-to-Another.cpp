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
public:
    string getDirections(TreeNode* root, int startValue, int destValue) 
    {
        string dirs1, dirs2;
        dfs(root, dirs1, startValue);
        dfs(root, dirs2, destValue);
        
        int k = 0;
        while (k<dirs1.size() && k<dirs2.size() && dirs1[k]==dirs2[k])
            k++;
        for (int i=k; i<dirs1.size(); i++)
            dirs1[i] = 'U';
        return dirs1.substr(k)+dirs2.substr(k);
    }
    
    bool dfs(TreeNode* node, string& dirs, int target)
    {
        if (node==NULL) return false;
        if (node->val == target) return true;
        
        if (node->left)
        {
            dirs.push_back('L');
            if (dfs(node->left, dirs, target))
                return true;
            dirs.pop_back();
        }
        if (node->right)
        {
            dirs.push_back('R');
            if (dfs(node->right, dirs, target))
                return true;
            dirs.pop_back();
        }
        return false;
    }
};
