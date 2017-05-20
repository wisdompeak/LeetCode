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
        
        vector<int>left;
        if (root->left!=NULL)
        {
            GoLeft(root->left,left);
            left.pop_back();
        }
            
        vector<int>right;
        if (root->right!=NULL)
        {
            GoRight(root->right,right);       
            right.pop_back();
        }
        reverse(right.begin(),right.end());
        
        vector<int>bottom;
        if (root->left!=NULL || root->right!=NULL)
            GoLeaf(root,bottom);
        
        for (int i=0; i<left.size(); i++)
            results.push_back(left[i]);
        for (int i=0; i<bottom.size(); i++)
            results.push_back(bottom[i]);            
        for (int i=0; i<right.size(); i++)
            results.push_back(right[i]);   
            
        return results;
        
    }
    
    void GoLeft(TreeNode* node, vector<int>&left)
    {
        if (node==NULL) return;
        
        while (node!=NULL)
        {
            left.push_back(node->val);
            if (node->left!=NULL)
                node=node->left;
            else
                node=node->right;
        }
    }
    
    void GoRight(TreeNode* node, vector<int>&right)
    {
        if (node==NULL) return;
        
        while (node!=NULL)
        {
            right.push_back(node->val);
            if (node->right!=NULL)
                node=node->right;
            else
                node=node->left;
        }
    }    
    
    void GoLeaf(TreeNode* node, vector<int>&bottom)
    {
        if (node==NULL) return;
        
        if (node->left==NULL && node->right==NULL)
            bottom.push_back(node->val);
        else
        {
            GoLeaf(node->left,bottom);
            GoLeaf(node->right,bottom);
        }
    }
};
