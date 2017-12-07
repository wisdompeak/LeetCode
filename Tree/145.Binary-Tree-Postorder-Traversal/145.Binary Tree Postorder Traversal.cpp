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
        vector<int>results;
        stack<TreeNode*>Stack;
        unordered_set<TreeNode*>Set;
        
        while (!Stack.empty() || root!=NULL)
        {
            if (root!=NULL)
            {
                Stack.push(root);
                root=root->left;
            }
            else
            {
                root=Stack.top();
                if (Set.find(root)==Set.end())
                {
                    Set.insert(root);
                    root = root->right;
                }
                else
                {
                    results.push_back(root->val);
                    Stack.pop();
                    root=NULL;
                }
            }
        }
        
        return results;
    }
};
