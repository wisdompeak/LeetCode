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
    vector<int> boundaryOfBinaryTree(TreeNode* root) 
    {
        vector<int>results;
        if (root==NULL) return results;
        
        results.push_back(root->val);
        
        vector<int>Left;
        if (root->left!=NULL)
        {
            GoLeft(root->left,Left);
            Left.pop_back();
        }
        
        vector<int>Bottom;
        if (root->left!=NULL || root->right!=NULL)
            GoBottom(root,Bottom);
        
        vector<int>Right;
        if (root->right!=NULL)
        {
            GoRight(root->right,Right);
            Right.pop_back();
        }
        reverse(Right.begin(),Right.end());
        
        for (int i=0; i<Left.size(); i++)
            results.push_back(Left[i]);

        for (int i=0; i<Bottom.size(); i++)
            results.push_back(Bottom[i]);
        
        for (int i=0; i<Right.size(); i++)
            results.push_back(Right[i]);    
        
        return results;
    }
    
    void GoLeft(TreeNode* root, vector<int>& Left)
    {
        if (root==NULL) return;
        
        Left.push_back(root->val);
        if (root->left!=NULL)
            GoLeft(root->left,Left);
        else if (root->right!=NULL)
            GoLeft(root->right,Left);
    }
    
    void GoRight(TreeNode* root, vector<int>& Right)
    {
        if (root==NULL) return;
        
        Right.push_back(root->val);
        if (root->right!=NULL)
            GoRight(root->right,Right);
        else if (root->left!=NULL)
            GoRight(root->left,Right);
    }    
    
    void GoBottom(TreeNode* root, vector<int>& Bottom)
    {
        if (root==NULL) return;
        if (root->left==NULL && root->right==NULL)
        {
            Bottom.push_back(root->val);
        }
        else
        {
            GoBottom(root->left,Bottom);
            GoBottom(root->right,Bottom);
        }
    }
};
