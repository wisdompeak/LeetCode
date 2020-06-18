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
    vector<pair<int,int>>nodes;
public:
    TreeNode* recoverFromPreorder(string S) 
    {        
        for (int i=0; i<S.size(); i++)
        {
            int j = i;
            while (j<S.size() && S[j]=='-')
                j++;
            int depth = j-i;
            i = j;
            while (j<S.size() && isdigit(S[j]))
                j++;
            int val = stoi(S.substr(i, j-i));
            nodes.push_back({val, max(0,depth)});
            i = j-1;
        }
        int num = 0;
        return DFS(0, num);
    }

    TreeNode* DFS(int cur, int& num)
    {
        TreeNode* root = new TreeNode(nodes[cur].first);
        int leftNum = 0, rightNum = 0;
        if (cur+1 < nodes.size() && nodes[cur+1].second == nodes[cur].second+1)
        {
            TreeNode* left = DFS(cur+1, leftNum);
            root->left = left;
        }        
        if (cur+leftNum+1 < nodes.size() && nodes[cur+leftNum+1].second == nodes[cur].second+1)
        {
            TreeNode* right = DFS(cur+leftNum+1, rightNum);
            root->right = right;
        }
        num = leftNum+rightNum+1;
        return root;
    }
};
