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
    int countNodes(TreeNode* root) 
    {
        int h = 0;
        TreeNode* node = root;
        while (node!=NULL)
        {
            h++;
            node = node->left;            
        }
        int low = (1<<(h-1));
        int hi = (1<<h)-1;
        
        while (low<hi)
        {
            int mid = low+(hi-low+1)/2;
            if (hasK(root,mid))
                low = mid;
            else
                hi = mid-1;
        }
        return low;
    }
    
    bool hasK(TreeNode* root, int K)
    {
        vector<int>path;
        while (K>0)
        {
            path.push_back(K);
            K = K/2;
        }
        for (int i=path.size()-1; i>=0; i--)
        {
            if (root==NULL) return false;
            if (i==0) return true;
            if (path[i-1]==path[i]*2)
                root = root->left;
            else
                root = root->right;            
        }
        return true;
    }
};
