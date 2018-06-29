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
    int count = 0;
public:
    int pathSum(TreeNode* root, int sum) 
    {
        if (root==NULL) return 0;
        Map[0]=1;
        DFS(root,0,sum);
        return count;
    }
    
    void DFS(TreeNode* node, int curSum, int target)
    {
        if (node==NULL) return;
        
        curSum+=node->val;        
        count+= Map[curSum-target];
        
        Map[curSum]+=1;               
        DFS(node->left,curSum,target);
        DFS(node->right,curSum,target);        
        Map[curSum]-=1;
                
        return;                    
    }
};
