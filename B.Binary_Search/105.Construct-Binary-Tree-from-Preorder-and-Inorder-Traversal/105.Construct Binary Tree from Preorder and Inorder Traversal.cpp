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
    unordered_map<int,int>Map;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if (preorder.size()==0) return NULL;
        
        for (int i=0; i<inorder.size(); i++)
            Map[inorder[i]]=i;
        
        TreeNode* root = DFS(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
        
        return root;
    }
    
    TreeNode* DFS(vector<int>& preorder, int a, int b, vector<int>& inorder, int m, int n)
    {
        if (a>b)
            return NULL;
        
        TreeNode* root = new TreeNode(preorder[a]);
        
        int pos = Map[preorder[a]];
        root->left = DFS(preorder,a+1,a+pos-m,inorder,m,pos-1);
        root->right = DFS(preorder,a+pos-m+1,b,inorder,pos+1,n);
        return root;
    }
};
