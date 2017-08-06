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
    vector<vector<string>> printTree(TreeNode* root) 
    {
        int maxHeight = getHeight(root);
        int maxWidth = pow(2,maxHeight)-1;
        auto results=vector<vector<string>>(maxHeight,vector<string>(maxWidth));                
        DFS(root,0,0,maxWidth-1,results);        
        return results;
    }
    
    void DFS(TreeNode* root, int dep, int start, int end, vector<vector<string>>& results)
    {
        if (root==NULL) return;
        int pos=(start+end)/2;        
        results[dep][pos]=to_string(root->val);
        DFS(root->left,dep+1,start,pos-1,results);
        DFS(root->right,dep+1,pos+1,end,results);
    }
    
    int getHeight(TreeNode* root)
    {
        if (root==NULL) return 0;
        else return max(getHeight(root->left),getHeight(root->right))+1;
    }
    
};
