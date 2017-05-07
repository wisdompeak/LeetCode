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
    vector<int> preorderTraversal(TreeNode* root) 
    {
        vector<int>results;
        stack<TreeNode*>Stack;
        
        while (root!=NULL || !Stack.empty())
        {
            if (root!=NULL)
            {
                Stack.push(root);
                results.push_back(root->val);
                root=root->left;
            }
            else
            {
                root=Stack.top();
                Stack.pop();
                root=root->right;
            }
        }
        
        return results;
        
    }
};
