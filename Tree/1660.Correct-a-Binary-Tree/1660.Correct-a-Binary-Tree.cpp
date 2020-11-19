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
    TreeNode* correctBinaryTree(TreeNode* root) 
    {
        unordered_set<int>Set;
        queue<TreeNode*>q;
        q.push(root);
        Set.insert(root->val);
        while (!q.empty())
        {
            int len = q.size();
            while (len--)
            {
                TreeNode* node = q.front();                
                q.pop();
                
                if (node->right)
                {
                    TreeNode* p = node->right;
                    if (p->right && Set.find(p->right->val)!=Set.end())
                    {
                        node->right = NULL;
                        return root;
                    }
                    q.push(p);
                    Set.insert(p->val);
                }
                if (node->left)
                {
                    TreeNode* p = node->left;
                    if (p->right && Set.find(p->right->val)!=Set.end())
                    {
                        node->left = NULL;
                        return root;
                    }
                    q.push(p);
                    Set.insert(p->val);
                }
            }
        }
        return root;
    }
    
};
