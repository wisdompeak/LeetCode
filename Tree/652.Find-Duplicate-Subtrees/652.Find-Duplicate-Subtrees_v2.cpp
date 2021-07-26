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
 using LL = long long;
class Solution {
    vector<TreeNode*>rets;
    unordered_map<LL, int>key2Id;
    unordered_map<LL, int>key2count;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        getID(root);
        return rets;
    }

    LL getID(TreeNode* node)
    {
        if (node==NULL) return 0;
        LL key = (getID(node->left)<<32) + (getID(node->right)<<16) + node->val;

        if (key2Id.find(key)==key2Id.end())
        {                        
            key2Id[key] = key2Id.size();
            key2count[key] = 1;
        }
        else
        {
            key2count[key] += 1;            
            if (key2count[key]==2)
            {
                rets.push_back(node);
            }
        }

        return key2Id[key];
    }
};
