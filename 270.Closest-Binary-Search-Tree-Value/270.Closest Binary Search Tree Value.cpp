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
    double closestValue(TreeNode* root, double target) 
    {

        
        if (root==NULL)
            return 0;
        
        double temp = root->val;        
        
       while (root!=NULL)
       {
           
           if (fabs(root->val-target) < fabs(temp-target))
                temp=root->val;
           
           if (root->val == target)
                return target;
           else if(root->val < target)
                root=root->right;
           else if(root->val > target)
                root=root->left;             
       }
       
       return temp;
    }
};
