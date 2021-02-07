/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
typedef long long ll;
class Solution {
    vector<TreeNode*>rets;
    unordered_map<ll, int>key2Id;
    unordered_map<ll, int>key2count;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        getId(root);
        return rets;        
    }
    
    ll getId(TreeNode* node)
    {
        if (node==NULL) return 0;
        
        ll key = (getId(node->left)<<32) + (getId(node->right)<<16) + node->val;
        key2count[key]+=1;
        if (key2count[key]==1)
        {
            key2Id[key] = key2Id.size()+1;                        
        }
        else if (key2count[key]==2)
        {            
            rets.push_back(node);            
        }
        
        return key2Id[key];
    }
    
    
};
