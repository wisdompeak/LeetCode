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
        vector<int>nums1, nums2;
        string dirs1, dirs2;
        dfs(root, nums1, dirs1, startValue);
        dfs(root, nums2, dirs2, destValue);
        
        // nums1: 0-1-3;  nums2: 0-2-6
        // dirs1: L-U-U;  dirs2: R-R-L
        int k = 0;
        while (k<nums1.size() && k<nums2.size() && nums1[k]==nums2[k])
            k++;
        for (int i=k; i<dirs1.size(); i++)
            dirs1[i] = 'U';
        return dirs1.substr(k)+dirs2.substr(k);
    }
    
    bool dfs(TreeNode* node, vector<int>&nums, string& dirs, int target)
    {
        if (node==NULL) return false;
        if (node->val == target) return true;
        
        if (node->left)
        {
            nums.push_back(node->left->val);
            dirs.push_back('L');
            if (dfs(node->left, nums, dirs, target))
                return true;
            nums.pop_back();
            dirs.pop_back();
        }
        if (node->right)
        {
            nums.push_back(node->right->val);
            dirs.push_back('R');
            if (dfs(node->right, nums, dirs, target))
                return true;
            nums.pop_back();
            dirs.pop_back();
        }
        return false;
    }
};
