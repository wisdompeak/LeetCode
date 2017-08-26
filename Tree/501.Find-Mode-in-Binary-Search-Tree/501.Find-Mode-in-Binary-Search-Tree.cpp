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
    int maxFreq=0;
    int currentFreq=0;
    int prev;
    vector<int>results;
public:
    vector<int> findMode(TreeNode* root) 
    {
        DFS(root);
        return results;
    }
    
    void DFS(TreeNode* root)
    {
        if (root==NULL) return;
        
        DFS(root->left);
        
        if (maxFreq==0)
        {
            maxFreq=1;
            currentFreq=1;
            prev=root->val;
            results.push_back(root->val);
        }
        else
        {
            if (root->val==prev)
            {
                prev=root->val;
                currentFreq++;
                if (currentFreq==maxFreq)
                {
                    results.push_back(root->val);                
                }
                else if (currentFreq>maxFreq)
                {
                    results={root->val};
                    maxFreq=currentFreq;
                }                    
            }
            else
            {
                prev=root->val;
                currentFreq=1;
                if (maxFreq==1)
                    results.push_back(root->val);
            }
        }
        
        DFS(root->right);
    }
};
