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
    TreeNode* deleteNode(TreeNode* root, int key) 
	{
        if (root==NULL) return NULL;
        
        if (root->val<key)
	{
		root->right = deleteNode(root->right,key);
		return root;
	}
	else if (root->val>key)
	{
		root->left = deleteNode(root->left,key);
		return root;
	}
	else if (root->val==key)
	{
           	if (root->right==NULL)
                	return root->left;				
		else
            	{
                	TreeNode* node=root->right;
                	while (node->left!=NULL)
                    		node = node->left;
                	root->val=node->val;
                	root->right = deleteNode(root->right,node->val);
                	return root;
            	}
	}
    }
};
