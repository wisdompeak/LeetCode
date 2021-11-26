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
    vector<int> postorderTraversal(TreeNode* root) 
    {        
        vector<int>rets;
        stack<pair<TreeNode*,int>>Stack;
        Stack.push({root, 0});

        while (!Stack.empty())
        {
            TreeNode* cur = Stack.top().first;
            int rev = Stack.top().second;
            Stack.pop();

            if (cur==NULL) continue;

            if (rev==1)
                rets.push_back(cur->val);
            else
            {
                Stack.push({cur, 1});
                Stack.push({cur->right, 0});
                Stack.push({cur->left, 0});
            }
        }
        return rets;
    }
};
