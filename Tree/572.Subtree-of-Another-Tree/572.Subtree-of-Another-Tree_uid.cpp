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
    unordered_map<ll, int>key2Id;
    unordered_map<ll, int>key2Count;
    unordered_map<ll, int>Id2key;

public:
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        getId(s);
        int ID = getId(t);
        for (auto x: key2Id)
        {
            if (x.second==ID)
                return key2Count[x.first] > 1;
        }
        return false;
    }
    
    ll getId(TreeNode* node)
    {
        if (node==NULL) return 0;        
        ll key = (getId(node->left)<<32) + (getId(node->right)<<16) + node->val;        
        key2Count[key]+=1;
        if (key2Id.find(key)==key2Id.end())
        {
            key2Id[key] = key2Id.size()+1;                        
        }        
        return key2Id[key];
    }
};
