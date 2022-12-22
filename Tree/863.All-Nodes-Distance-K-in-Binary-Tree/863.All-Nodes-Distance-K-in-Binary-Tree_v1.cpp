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
    vector<int>rets;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) 
    {
        DFS(root, target, K);
        return rets;
    }
    
    int DFS(TreeNode* node, TreeNode* target, int k)
    {
        if (node==NULL) return -1;
        
        if (node==target)
        {
            fetch(node, k);
            return 0;
        }
            
        
        int depth1 = DFS(node->left, target, k);        
        if (depth1 != -1)
        {
            if (depth1 == k-1)
                rets.push_back(node->val);
            else                
                fetch( node->right, k - depth1 -2 );
                
            return depth1+1;
        }
        
        int depth2 = DFS(node->right, target, k);
        if (depth2 != -1)
        {
            if (depth2 == k-1)
                rets.push_back(node->val);
            else    
                fetch( node->left, k - depth2 -2 );
            return depth2+1;
        }
        
        return -1;
    }
    
    void fetch(TreeNode* node, int k)
    {
        if (node==NULL) return;
        if (k<0) return;
        if (k==0)
        {
            rets.push_back(node->val);
            return;
        }
        fetch(node->left, k-1);
        fetch(node->right, k-1);        
    }
};


