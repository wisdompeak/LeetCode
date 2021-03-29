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
    unordered_map<int,int>Map;
    vector<int>voyage;
    vector<int>rets;
public:
    vector<int> flipMatchVoyage(TreeNode* root, vector<int>& voyage)         
    {
        this->voyage = voyage;
        for (int i=0; i<voyage.size(); i++)
            Map[voyage[i]] = i;
        if (checkFlip(root, 0, voyage.size()-1))
            return rets;
        else
            return {-1};
    }
    
    bool checkFlip(TreeNode* node, int a, int b)
    {
        if (a>b)
            return false;
        if (node->val != voyage[a])
            return false;        
        if (!node->left && !node->right)
            return a==b;
        
        if (!node->left)
            return checkFlip(node->right, a+1, b);
        else if (!node->right)
            return checkFlip(node->left, a+1, b);
        else
        {
            if (node->left->val==voyage[a+1])
            {
                int pos = Map[node->right->val];
                return checkFlip(node->left, a+1, pos-1) && checkFlip(node->right, pos, b) ;
            }
            else
            {
                rets.push_back(node->val);
                int pos = Map[node->left->val];
                return checkFlip(node->right, a+1, pos-1) && checkFlip(node->left, pos, b) ;
            }            
        }        
    }
};
