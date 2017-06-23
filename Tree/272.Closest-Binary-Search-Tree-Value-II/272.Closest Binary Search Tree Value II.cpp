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
    vector<int> closestKValues(TreeNode* root, double target, int k) 
    {
        queue<int>q;
        
        DFS(root,q,target,k);
        
        vector<int>result;
        while (!q.empty())
        {
            result.push_back(q.front());
            q.pop();
        }
        return result;
    }
    
    void DFS(TreeNode* root, queue<int>&q, double target, int k)
    {
        if (root==NULL) return;
        
        DFS(root->left, q, target, k);
        
        if (q.size()<k)
        {
            q.push(root->val);
            DFS(root->right,q,target,k);
        }
        else
        {
            if (abs(q.front()-target)>abs(root->val-target))
            {
                q.push(root->val);
                q.pop();
                DFS(root->right,q,target,k);
            }
            else
                return;
        }
        
    }
};
