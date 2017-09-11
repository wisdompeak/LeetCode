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
    unordered_map<int,pair<int,int>>Map;
public:
    int widthOfBinaryTree(TreeNode* root) 
    {
        DFS(root,0,1);
        int result=0;
        for (auto a:Map)
        {
            result=max(result,a.second.second-a.second.first+1);
        }
        return result;
    }
    
    void DFS(TreeNode* node, int level, int order)
    {
        if (node==NULL) return;
        if (Map[level].first==0 || order<=Map[level].first)
            Map[level].first=order;
        if (Map[level].second==0 ||order>=Map[level].second)
            Map[level].second=order;
        DFS(node->left,level+1,order*2-1);
        DFS(node->right,level+1,order*2);
    }
};
