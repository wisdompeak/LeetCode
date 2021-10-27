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
    int countNodes(TreeNode* root) 
    {
        if (root==NULL) return 0;
        
        int ret = 1;        
        int h1 = findLeftDepth(root->left);
        int h2 = findRightDepth(root->left);
        int h3 = findLeftDepth(root->right);
        int h4 = findRightDepth(root->right);
        
        if (h1==h2)
        {
            ret += pow(2,h1)-1;
            return ret+countNodes(root->right);
        }           
        else 
        {
            ret += pow(2,h3)-1;
            return ret+countNodes(root->left);            
        }            
    }
    
    int findLeftDepth(TreeNode* node)
    {
        int count = 0;
        while (node!=NULL)
        {
            count++;
            node=node->left;
        }        
        return count;
    }
    
    int findRightDepth(TreeNode* node)
    {
        int count = 0;
        while (node!=NULL)
        {
            count++;
            node=node->right;
        }        
        return count;
    }
};
