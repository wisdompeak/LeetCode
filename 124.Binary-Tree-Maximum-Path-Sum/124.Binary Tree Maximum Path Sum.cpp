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
    int result;
    
public:
    int maxPathSum(TreeNode* root) 
    {
        result = INT_MIN;
        
        maxSum(root);
        
        return result;
    }
    
    int maxSum(TreeNode* node)
    {
        if (node==NULL) return 0;
        
        int s1=maxSum(node->left);
        int s2=maxSum(node->right);
        
        int temp = max(s1+node->val,s2+node->val);
        temp = max(temp, node->val);

        result = max(result,temp);
        result = max(result,s1+s2+node->val);
        
        //cout<<node->val<<":"<<temp<<endl;
        
        return temp;
    }
    

};
