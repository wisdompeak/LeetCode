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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        stack<TreeNode*>Stack;
        for (int i=0; i<nums.size(); i++)
        {
            TreeNode* node = new TreeNode(nums[i]);
            while (!Stack.empty() && Stack.top()->val < nums[i])
            {
                node->left = Stack.top();
                Stack.pop();
            }
            if (!Stack.empty()) 
                Stack.top()->right = node;
            Stack.push(node);
        }
        while (Stack.size()>1)
            Stack.pop();
        return Stack.top();
    }
};
