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
    // 0: uncovered
    // 1: with camera
    // 2: covered without camera
    int result;
public:
    int minCameraCover(TreeNode* root) 
    {
        result = 0;
        int temp = DFS(root);
        if (temp==0) result++;
        return result;
    }
    
    int DFS(TreeNode* node)
    {
        if (node==NULL) return 2;
        int left = DFS(node->left);
        int right = DFS(node->right);
        if (left==0 || right==0)
        {
            result++;
            return 1;
        }
        if (left==2 && right==2)
        {
            return 0;
        }
        return 2;
    }
};
