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
    unordered_map<TreeNode*,int>Rob;
    unordered_map<TreeNode*,int>noRob;
public:
    int rob(TreeNode* root) 
    {
        return DFS(root,1);
    }

    int DFS(TreeNode* node, int flag)
    {
        if (node==NULL) return 0;
        if (flag==0 && noRob.find(node)!=noRob.end())
            return noRob[node];
        if (flag==1 && Rob.find(node)!=Rob.end())
            return Rob[node];

        int ret;
        if (flag==0)
            ret = DFS(node->left, 1) + DFS(node->right,1);
        else
            ret = max(node->val + DFS(node->left, 0) + DFS(node->right,0), DFS(node->left,1)+DFS(node->right,1));

        if (flag==0) noRob[node] = ret;
        else Rob[node] = ret;

        return ret;
    }
};
