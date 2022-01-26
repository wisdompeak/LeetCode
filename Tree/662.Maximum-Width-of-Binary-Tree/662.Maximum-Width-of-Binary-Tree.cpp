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
    int widthOfBinaryTree(TreeNode* root) 
    {
        root->val = 0;
        deque<TreeNode*>q;
        q.push_back(root);
        int ans = 1;

        while (!q.empty())
        {
            int len = q.size();
            ans = max(ans, q.back()->val - q.front()->val + 1);

            int base = q.front()->val;

            while (len--)
            {            
                TreeNode* node = q.front();
                q.pop_front();
                
                if (node->left)
                {
                    node->left->val = (node->val-base)*2+1;
                    q.push_back(node->left);
                }
                if (node->right)
                {
                    node->right->val = (node->val-base)*2+2;
                    q.push_back(node->right);
                }
            }
        }
        return ans;
    }
};
