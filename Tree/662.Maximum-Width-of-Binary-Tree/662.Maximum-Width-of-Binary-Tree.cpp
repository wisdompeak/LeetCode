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

            int flag = (len == 1);

            while (len--)
            {            
                TreeNode* node = q.front();
                q.pop_front();

                if (flag==1) node->val = 0;
                
                if (node->left)
                {
                    node->left->val = node->val*2+1;
                    q.push_back(node->left);
                }
                if (node->right)
                {
                    node->right->val = node->val*2+2;
                    q.push_back(node->right);
                }
            }
        }
        return ans;
    }
    

};
