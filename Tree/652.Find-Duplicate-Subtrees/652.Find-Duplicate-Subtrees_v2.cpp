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
class Solution {
    unordered_map<string, int> key2Id;
    unordered_map<string, int> key2count;
    vector<TreeNode*> rets;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        getId(root);
        return rets;        
    }
    
    int getId(TreeNode* node)
    {
        if (node==NULL) return 0;
        
        string key = to_string(node->val) + "#" + to_string(getId(node->left)) + "#" + to_string(getId(node->right));
        
        if (key2Id.find(key) == key2Id.end())
        {
            key2Id[key] = key2Id.size()+1;
            key2count[key] = 1;
        }
        else
        {
            key2count[key]+=1;
            if (key2count[key]==2)
            {
                rets.push_back(node);
            }
        }
        
        return key2Id[key];
    }
};
