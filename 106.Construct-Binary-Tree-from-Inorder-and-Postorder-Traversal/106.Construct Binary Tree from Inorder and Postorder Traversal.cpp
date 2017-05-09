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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        for (int i=0; i<inorder.size(); i++)
            Map[inorder[i]]=i;
        return DFS(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    
    TreeNode* DFS(vector<int>& inorder, int a, int b, vector<int>& postorder, int m, int n)
    {
        if (a>b) return NULL;
        
        TreeNode* root=new TreeNode(postorder[n]);
        int pos=Map[postorder[n]];
        root->left = DFS(inorder,a,pos-1,postorder,m,m+pos-1-a);
        root->right = DFS(inorder,pos+1,b,postorder,m+pos-a,n-1);
        
        return root;
    }
};
