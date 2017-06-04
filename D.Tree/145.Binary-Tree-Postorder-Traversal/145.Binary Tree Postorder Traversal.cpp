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
        unordered_map<TreeNode*,int>Map;
        stack<TreeNode*>Stack;
        vector<int>results;
        
        while(root!=NULL || !Stack.empty())
        {
            if (root!=NULL)
            {
                Stack.push(root);
                root=root->left;
            }
            else
            {
                root=Stack.top();
                if (Map.find(root)==Map.end())
                {
                    Map[root]=1;
                    root=root->right;
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
