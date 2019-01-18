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
    bool isCompleteTree(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        while (q.front()!=NULL)
        {            
            q.push(q.front()->left);            
            q.push(q.front()->right);
            q.pop();
        }
        while (!q.empty())
        {
            if (q.front()!=NULL) return false;
            q.pop();
        }
        return true;
        
    }
};
