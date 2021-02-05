/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int>suf;
    vector<int>list;
    int dp[2500];
public:
    bool isSubPath(ListNode* head, TreeNode* root) 
    {
        suf = preprocess(head);
        return dfs(root, 0);
    }

    bool dfs(TreeNode* node, int i)
    {
        if (node==NULL) return false;
        
        if (i==0)
        {
            dp[i] = (list[0] == node->val);            
        }
        else
        {
            int j = dp[i-1];
            while (j>0 && list[j]!=node->val)
                j = suf[j-1];
            dp[i] = j + (list[j]==node->val);
        }
        
        if (dp[i]==list.size()) 
            return true;
        else
            return dfs(node->left, i+1) || dfs(node->right, i+1);
    }


    vector<int> preprocess(ListNode* head)
    {
        while (head!=NULL)
        {
            list.push_back(head->val);
            head = head->next;
        }
        int n = list.size();
        vector<int>dp(n);
        for (int i=1; i<n; i++)
        {
            int j = dp[i-1];
            while (j>0 && list[j]!=list[i])
                 j = dp[j-1];
            dp[i] = j+(list[j]==list[i]);
        }
        return dp;
    }
};
