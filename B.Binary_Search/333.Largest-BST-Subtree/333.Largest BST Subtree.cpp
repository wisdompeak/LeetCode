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
    int result = INT_MIN;
public:
    int largestBSTSubtree(TreeNode* root) 
    {
        if (root==NULL) return 0;
        
        int mmin,mmax;
        int res = DFS(root,mmin,mmax);
        return result;
    }
    
    int DFS(TreeNode* root, int& mmin, int& mmax)
    {
        if (root==NULL) return 0;

        int left_min=0, left_max=0, right_min=0, right_max=0;
        
        int n1 = DFS(root->left, left_min, left_max);
        int n2 = DFS(root->right, right_min, right_max);
        
       if ((n1==0 || n1>0 && left_max<root->val) && (n2==0 || n2>0 && right_min>root->val))
        {
            mmin = n1==0 ? root->val:left_min;
            mmax = n2==0 ? root->val:right_max;                
            result = max(result,n1+n2+1);
            return n1+n2+1;
        }
        else
            return -1;
    }
};
