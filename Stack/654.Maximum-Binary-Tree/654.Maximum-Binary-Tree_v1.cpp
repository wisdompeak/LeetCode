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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        return DFS(nums,0,nums.size()-1);
    }
    
    TreeNode* DFS(vector<int>& nums, int start, int end)
    {
        int MAX=INT_MIN;
        int index=0;
        if (start>end) return NULL;
        
        for (int i=start; i<=end; i++)
        {
            if (nums[i]>MAX)
            {
                MAX=nums[i];
                index=i;
            }
        }
        
        TreeNode* root=new TreeNode(nums[index]);
        root->left=DFS(nums,start,index-1);
        root->right=DFS(nums,index+1,end);
        return root;
    }
};
