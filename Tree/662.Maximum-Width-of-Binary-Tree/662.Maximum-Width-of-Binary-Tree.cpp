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
        vector<TreeNode*>q;
        q.push_back(root);
        int ans = 1;

        while (!q.empty())
        {
            int len = q.size();
            ans = max(ans, q.back()->val - q[0]->val + 1);            

            vector<long long>vals;
            vector<TreeNode*>p;

            for (int i=0; i<len; i++)
            {
                TreeNode* node = q[i];
                if (node->left)
                {
                    vals.push_back((long long)node->val * 2 + 1);
                    p.push_back(node->left);
                }
                if (node->right)
                {
                    vals.push_back((long long)node->val * 2 + 2);
                    p.push_back(node->right);
                }
            }
            
            if (!p.empty()) 
            {
                for (int i=0; i<p.size() ; i++)
                {
                    p[i]->val = (int)(vals[i] - vals[0]);
                }
            }
            
            q = p;
        }
        return ans;
    }
};
