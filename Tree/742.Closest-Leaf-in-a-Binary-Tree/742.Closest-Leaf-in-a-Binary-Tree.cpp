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
    unordered_map<TreeNode*,int>Dist2Leaf;
    unordered_map<TreeNode*,int>ClosestLeaf;
    int dist=INT_MAX;
    int result;
public:
    int findClosestLeaf(TreeNode* root, int k) 
    {
        int temp;
        temp = DFS_find_closest_leaf(root);
        temp = DFS_find_k(root,k);
        return result;
    }
    
    int DFS_find_closest_leaf(TreeNode* root)
    {
        if (root==NULL) 
            return INT_MAX;
        
        if (root->left==NULL && root->right==NULL)
        {
            Dist2Leaf[root]=0;
            ClosestLeaf[root]=root->val;
            return 0;
        }
        
        int L=DFS_find_closest_leaf(root->left);
        int R=DFS_find_closest_leaf(root->right);
        
        if (L>R)
        {
            Dist2Leaf[root]=R+1;
            ClosestLeaf[root]=ClosestLeaf[root->right];            
        }
        else
        {
            Dist2Leaf[root]=L+1;
            ClosestLeaf[root]=ClosestLeaf[root->left];            
        }        
        
        return Dist2Leaf[root];
    }
    
    int DFS_find_k(TreeNode* root, int k)
    {
        if (root==NULL) 
            return -1;
        
        if (root->val==k)
        {
            if (dist > Dist2Leaf[root])
            {
                dist = Dist2Leaf[root];
                result = ClosestLeaf[root];
            }
            return 0;
        }
        
        int L=DFS_find_k(root->left,k);
        if (L!=-1)
        {
            if (root->right!=NULL && dist > L+2+Dist2Leaf[root->right])
            {
                dist = L+2+Dist2Leaf[root->right];
                result = ClosestLeaf[root->right];                    
            }
            return L+1;
        }
        
        int R=DFS_find_k(root->right,k);
        if (R!=-1)
        {
            if (root->left!=NULL && dist > R+2+Dist2Leaf[root->left])
            {
                dist = L+2+Dist2Leaf[root->left];
                result = ClosestLeaf[root->left];                    
            }
            return R+1;
        }
        
        return -1;
    }
    
    
};
