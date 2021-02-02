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
public:
    bool isSubtree(TreeNode* s, TreeNode* t) 
    {
        vector<int>S, T;
        convert(s, S);
        convert(t, T);
        vector<int>suf = preprocess(T);
        int n = S.size();
        vector<int>dp(n,0);
        dp[0] = (T[0]==S[0]);
        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];
            while (j>0 && T[j]!=S[i])
                j = suf[j-1];
            dp[i] = j+(T[j]==S[i]);
            if (dp[i] == T.size())
                return true;
        }
        return false;
    }

    void convert(TreeNode* node, vector<int>&arr)
    {
        if (node==NULL)
        {
            arr.push_back(INT_MAX);
            return;
        }
        arr.push_back(node->val);
        convert(node->left, arr);
        convert(node->right, arr);
    }

    vector<int> preprocess(vector<int>& P)
    {
        int n = P.size();
        vector<int>dp(n,0);
        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];
            while (j>0 && P[j]!=P[i])
                j = dp[j-1];
            dp[i] = j+(P[j]==P[i]);
        }
        return dp;
    }
};
