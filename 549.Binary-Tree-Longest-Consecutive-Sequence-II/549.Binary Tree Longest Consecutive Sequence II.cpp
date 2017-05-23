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
    unordered_map<TreeNode*,int>IS;
    unordered_map<TreeNode*,int>DS;
    int result=0;
public:
    int longestConsecutive(TreeNode* root) 
    {
        if (root==NULL) return 0;
        
        int x=longest_increase(root);
        int y=longest_decrease(root);
        DFS(root);
        return result;
    }
    
    void DFS(TreeNode* node)
    {
        if (node==NULL) return;
        DFS(node->left);
        result = max(result,IS[node]+DS[node]-1);
        //cout<<node->val<<" "<<IS[node]<<" "<<DS[node]<<endl;
        DFS(node->right);
    }
    
    int longest_increase(TreeNode* node)
    {
        if (node==NULL) return 0;
        
        int res = 1;
        if (node->left!=NULL)
        {
            int temp = longest_increase(node->left);
            if (node->val+1==node->left->val)
                res = max(res,temp+1);
        }
        if (node->right!=NULL)
        {
            int temp = longest_increase(node->right);
            if (node->val+1==node->right->val)
                res = max(res,temp+1);
        }
        
        IS[node]=res;
        return res;
    }

    int longest_decrease(TreeNode* node)
    {
        if (node==NULL) return 0;
        
        int res = 1;
        if (node->left!=NULL)
        {
            int temp = longest_decrease(node->left);
            if (node->val-1==node->left->val)
                res = max(res,temp+1);
        }
        if (node->right!=NULL)
        {
            int temp = longest_decrease(node->right);
            if (node->val-1==node->right->val)
                res = max(res,temp+1);
        }
        DS[node]=res;
        return res;
    }    
};
